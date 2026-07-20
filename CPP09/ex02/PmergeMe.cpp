#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cerrno>
#include <stdexcept>

PmergeMe::PmergeMe() : vectorTime(0), dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other){
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    if (this != &other){
        input = other.input;
        vectorResult = other.vectorResult;
        dequeResult = other.dequeResult;
        vectorTime = other.vectorTime;
        dequeTime = other.dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}


std::vector<size_t> PmergeMe::jacobsthalOrder(size_t count) const {
    std::vector<size_t> order;
    if (count <= 1)
        return order;

    std::vector<long> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < static_cast<long>(count))
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);
    
    std::vector<bool> used(count, false);
    used[0] = true;

    for (size_t step = 3; step < jac.size(); step++){
        long jumpTarget = jac[step];
        long stopBackward = jac[step - 1] + 1;
        if (jumpTarget > static_cast<long>(count)){
            jumpTarget = static_cast<long>(count);
        }
        for (long i = jumpTarget; i >= stopBackward; i--){
            if (i >= 1 && i <= static_cast<long>(count) && !used[i - 1]){
                order.push_back(static_cast<size_t>(i - 1));
                used[i - 1] = true;
            }
        }
    }

    for (size_t i = 1; i < count; i++){
        if (!used[i]){
            order.push_back(i);
            used[i] = true;
        }
    }

    return order;
}

std::vector<long> PmergeMe::sortVector(std::vector<long> numbers){
    if (numbers.size() <= 1)
        return numbers;

    bool hasStraggler = (numbers.size() % 2 == 1);
    long straggler = hasStraggler ? numbers.back() : 0;
    size_t pairCount = hasStraggler ? numbers.size() - 1 : numbers.size();

    std::vector<long> bigNumbers;
    std::vector<std::pair<long, long> > pairs;

    for (size_t i = 0; i < pairCount; i += 2){
        long a = numbers[i];
        long b = numbers[i + 1];
        long big = (a > b) ? a : b;
        long small = (a > b) ? b : a;
        bigNumbers.push_back(big);
        pairs.push_back(std::make_pair(big, small));
    }

    std::vector<long> chain = sortVector(bigNumbers);

    std::vector<long> smallNumbers(chain.size());
    for (size_t i = 0; i < chain.size(); i++){
        for (size_t j = 0; j < pairs.size(); j++){
            if (pairs[j].first == chain[i]){
                smallNumbers[i] = pairs[j].second;
                break;
            }
        }
    }

    std::vector<size_t> tracker(smallNumbers.size());
    for (size_t i = 0; i < tracker.size(); i++) {
        tracker[i] = i; 
    }

    if (!chain.empty()){
        chain.insert(chain.begin(), smallNumbers[0]);
        for (size_t i = 0; i < tracker.size(); i++) {
            tracker[i]++;
        }
    }

    std::vector<size_t> order = jacobsthalOrder(smallNumbers.size());
    for (size_t i = 0; i < order.size(); i++){
        size_t idx = order[i];
        long smallerVal = smallNumbers[idx];
        size_t stopPos = tracker[idx]; 
        
        std::vector<long>::iterator insertPos = std::lower_bound(chain.begin(), chain.begin() + stopPos, smallerVal);
        
        size_t dist = std::distance(chain.begin(), insertPos);
        chain.insert(insertPos, smallerVal);
        for (size_t j = 0; j < tracker.size(); j++) {
            if (tracker[j] >= dist) {
                tracker[j]++;
            }
        }
    }

    if (hasStraggler){
        std::vector<long>::iterator insertPos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(insertPos, straggler);
    }

    return chain;
}

std::deque<long> PmergeMe::sortDeque(std::deque<long> numbers){
    if (numbers.size() <= 1)
        return numbers;

    bool hasStraggler = (numbers.size() % 2 == 1);
    long straggler = hasStraggler ? numbers.back() : 0;
    size_t pairCount = hasStraggler ? numbers.size() - 1 : numbers.size();

    std::deque<long> bigNumbers;
    std::vector<std::pair<long, long> > pairs;

    for (size_t i = 0; i < pairCount; i += 2){
        long a = numbers[i];
        long b = numbers[i + 1];
        long big = (a > b) ? a : b;
        long small = (a > b) ? b : a;
        bigNumbers.push_back(big);
        pairs.push_back(std::make_pair(big, small));
    }

    std::deque<long> chain = sortDeque(bigNumbers);

    std::deque<long> smallNumbers(chain.size());
    for (size_t i = 0; i < chain.size(); i++){
        for (size_t j = 0; j < pairs.size(); j++){
            if (pairs[j].first == chain[i]){
                smallNumbers[i] = pairs[j].second;
                break;
            }
        }
    }

    std::vector<size_t> tracker(smallNumbers.size());
    for (size_t i = 0; i < tracker.size(); i++) {
        tracker[i] = i;
    }

    if (!chain.empty()){
        chain.insert(chain.begin(), smallNumbers[0]);
        for (size_t i = 0; i < tracker.size(); i++) {
            tracker[i]++;
        }
    }

    std::vector<size_t> order = jacobsthalOrder(smallNumbers.size());
    for (size_t i = 0; i < order.size(); i++){
        size_t idx = order[i];
        long smallerVal = smallNumbers[idx];
        size_t stopPos = tracker[idx]; 
        
        std::deque<long>::iterator insertPos = std::lower_bound(chain.begin(), chain.begin() + stopPos, smallerVal);

        size_t dist = std::distance(chain.begin(), insertPos);
        chain.insert(insertPos, smallerVal);
        for (size_t k = 0; k < tracker.size(); k++) {
            if (tracker[k] >= dist) {
                tracker[k]++;
            }
        }
    }

    if (hasStraggler){
        std::deque<long>::iterator insertPos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(insertPos, straggler);
    }

    return chain;
}

void PmergeMe::parseInput(int ac, char **av){
    if (ac < 2){
        throw std::runtime_error("Error: not enough arguments.");
    }

    for (int i = 1; i < ac; i++){
        std::string token(av[i]);

        if (token.empty())
            throw std::runtime_error("Error: empty argument.");
        for (size_t j = 0; j < token.length(); j++){
            if (!std::isdigit(token[j]))
                throw std::runtime_error("Error: invalid character.");
        }

        errno = 0;
        long value = std::strtol(token.c_str(), NULL, 10);
        if (errno == ERANGE)
            throw std::runtime_error("Error: number is out of range.");
        if (value <= 0 || value > INT_MAX)
            throw std::runtime_error("Error: invalid number.");

        input.push_back(value);
    }

    std::vector<long> check(input);
    std::sort(check.begin(), check.end());
    for (size_t i = 1; i < check.size(); i++){
        if (check[i] == check[i - 1])
            throw std::runtime_error("Error: duplicate numbers.");
    }
}

void PmergeMe::runVectorSort(){
    std::vector<long> copy(input);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    vectorResult = sortVector(copy);

    clock_gettime(CLOCK_MONOTONIC, &end);
    vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;
}

void PmergeMe::runDequeSort(){
    std::deque<long> copy(input.begin(), input.end());

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    dequeResult = sortDeque(copy);

    clock_gettime(CLOCK_MONOTONIC, &end);
    dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;
}

void PmergeMe::printResults() const {
    std::cout << "Before:";
    for (size_t i = 0; i < input.size(); i++)
        std::cout << " " << input[i];
    std::cout << std::endl;

    std::cout << "After:";
    for (size_t i = 0; i < vectorResult.size(); i++)
        std::cout << " " << vectorResult[i];
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);

    std::cout << "Time to process a range of " << input.size()
               << " elements with std::vector : " << vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << input.size()
                << " elements with std::deque : " << dequeTime <<  " us" << std::endl;
}

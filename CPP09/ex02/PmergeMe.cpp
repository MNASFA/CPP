#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cerrno>
#include <sys/time.h>
#include <stdexcept>

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other){
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    if (this != &other){
        _input = other._input;
        _vectorResult = other._vectorResult;
        _dequeResult = other._dequeResult;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

/*
** Jacobsthal numbers: J(0)=0, J(1)=1, J(n) = J(n-1) + 2*J(n-2)
** Returns the 0-indexed insertion order for elements 1..count-1
** (element 0 is always inserted first, separately, before this is used).
*/
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

    for (size_t k = 3; k < jac.size(); k++){
        long upper = jac[k];
        long lower = jac[k - 1] + 1;
        if (upper > static_cast<long>(count))
            upper = static_cast<long>(count);
        for (long idx = upper; idx >= lower; idx--){
            if (idx >= 1 && idx <= static_cast<long>(count) && !used[idx - 1]){
                order.push_back(static_cast<size_t>(idx - 1));
                used[idx - 1] = true;
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

/* ---------------------------- VECTOR VERSION ---------------------------- */

std::vector<long> PmergeMe::mergeInsertSortVector(std::vector<long> arr){
    if (arr.size() <= 1)
        return arr;

    bool hasStraggler = (arr.size() % 2 == 1);
    long straggler = hasStraggler ? arr.back() : 0;
    size_t n = hasStraggler ? arr.size() - 1 : arr.size();

    std::vector<long> largers;
    std::vector<std::pair<long, long> > pairs; // (big, small), sorted by big for O(log n) lookup

    for (size_t i = 0; i < n; i += 2){
        long a = arr[i];
        long b = arr[i + 1];
        long big = (a > b) ? a : b;
        long small = (a > b) ? b : a;
        largers.push_back(big);
        pairs.push_back(std::make_pair(big, small));
    }
    std::sort(pairs.begin(), pairs.end());

    std::vector<long> chain = mergeInsertSortVector(largers);

    // Re-align companions to the POST-recursion sorted order of the larger
    // values (a_i), not their original pre-sort pairing index. Companions
    // are looked up via binary search on `pairs` (O(log n) instead of the
    // O(n) linear std::find used previously).
    std::vector<long> sortedChain = chain;
    std::vector<long> sortedSmallers(chain.size());
    for (size_t i = 0; i < chain.size(); i++){
        std::vector<std::pair<long, long> >::iterator it =
            std::lower_bound(pairs.begin(), pairs.end(), std::make_pair(chain[i], LONG_MIN));
        sortedSmallers[i] = it->second;
    }

    if (!chain.empty())
        chain.insert(chain.begin(), sortedSmallers[0]);

    std::vector<size_t> order = jacobsthalOrder(sortedSmallers.size());
    for (size_t i = 0; i < order.size(); i++){
        long largerVal = sortedChain[order[i]];
        long smallerVal = sortedSmallers[order[i]];
        // chain is always kept sorted, so a binary search finds largerVal's
        // current position in O(log n) instead of the O(n) linear std::find
        // used previously.
        std::vector<long>::iterator largerPos = std::lower_bound(chain.begin(), chain.end(), largerVal);
        std::vector<long>::iterator insertPos = std::lower_bound(chain.begin(), largerPos, smallerVal);
        chain.insert(insertPos, smallerVal);
    }

    if (hasStraggler){
        std::vector<long>::iterator insertPos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(insertPos, straggler);
    }

    return chain;
}

/* ---------------------------- DEQUE VERSION ---------------------------- */

std::deque<long> PmergeMe::mergeInsertSortDeque(std::deque<long> arr){
    if (arr.size() <= 1)
        return arr;

    bool hasStraggler = (arr.size() % 2 == 1);
    long straggler = hasStraggler ? arr.back() : 0;
    size_t n = hasStraggler ? arr.size() - 1 : arr.size();

    std::deque<long> largers;
    std::vector<std::pair<long, long> > pairs; // (big, small), sorted by big for O(log n) lookup

    for (size_t i = 0; i < n; i += 2){
        long a = arr[i];
        long b = arr[i + 1];
        long big = (a > b) ? a : b;
        long small = (a > b) ? b : a;
        largers.push_back(big);
        pairs.push_back(std::make_pair(big, small));
    }
    std::sort(pairs.begin(), pairs.end());

    std::deque<long> chain = mergeInsertSortDeque(largers);

    // Re-align companions to the POST-recursion sorted order of the larger
    // values (a_i), not their original pre-sort pairing index. Companions
    // are looked up via binary search on `pairs` (O(log n) instead of the
    // O(n) linear std::find used previously).
    std::deque<long> sortedChain = chain;
    std::deque<long> sortedSmallers(chain.size());
    for (size_t i = 0; i < chain.size(); i++){
        std::vector<std::pair<long, long> >::iterator it =
            std::lower_bound(pairs.begin(), pairs.end(), std::make_pair(chain[i], LONG_MIN));
        sortedSmallers[i] = it->second;
    }

    if (!chain.empty())
        chain.insert(chain.begin(), sortedSmallers[0]);

    std::vector<size_t> order = jacobsthalOrder(sortedSmallers.size());
    for (size_t i = 0; i < order.size(); i++){
        long largerVal = sortedChain[order[i]];
        long smallerVal = sortedSmallers[order[i]];
        // chain is always kept sorted, so a binary search finds largerVal's
        // current position in O(log n) instead of the O(n) linear std::find
        // used previously.
        std::deque<long>::iterator largerPos = std::lower_bound(chain.begin(), chain.end(), largerVal);
        std::deque<long>::iterator insertPos = std::lower_bound(chain.begin(), largerPos, smallerVal);
        chain.insert(insertPos, smallerVal);
    }

    if (hasStraggler){
        std::deque<long>::iterator insertPos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(insertPos, straggler);
    }

    return chain;
}

/* ------------------------------- PUBLIC API ------------------------------ */

void PmergeMe::parseInput(int argc, char **argv){
    if (argc < 2)
        throw std::runtime_error("no arguments");

    for (int i = 1; i < argc; i++){
        std::string token(argv[i]);

        if (token.empty())
            throw std::runtime_error("empty token");
        for (size_t j = 0; j < token.length(); j++){
            if (!std::isdigit(static_cast<unsigned char>(token[j])))
                throw std::runtime_error("non-digit character");
        }

        errno = 0;
        char *end;
        long value = std::strtol(token.c_str(), &end, 10);
        if (*end != '\0' || errno == ERANGE)
            throw std::runtime_error("out of range");
        if (value <= 0 || value > INT_MAX)
            throw std::runtime_error("value out of bounds");

        _input.push_back(value);
    }

    std::vector<long> check(_input);
    std::sort(check.begin(), check.end());
    for (size_t i = 1; i < check.size(); i++){
        if (check[i] == check[i - 1])
            throw std::runtime_error("duplicate value");
    }
}

void PmergeMe::runVectorSort(){
    std::vector<long> work(_input);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    _vectorResult = mergeInsertSortVector(work);

    gettimeofday(&end, NULL);
    _vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::runDequeSort(){
    std::deque<long> work(_input.begin(), _input.end());

    struct timeval start, end;
    gettimeofday(&start, NULL);

    _dequeResult = mergeInsertSortDeque(work);

    gettimeofday(&end, NULL);
    _dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::printResults() const {
    std::cout << "Before:";
    for (size_t i = 0; i < _input.size(); i++)
        std::cout << " " << _input[i];
    std::cout << std::endl;

    std::cout << "After:";
    for (size_t i = 0; i < _vectorResult.size(); i++)
        std::cout << " " << _vectorResult[i];
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _input.size()
               << " elements with std::vector : " << _vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _input.size()
               << " elements with std::deque : " << _dequeTime << " us" << std::endl;
}
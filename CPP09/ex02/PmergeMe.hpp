#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iomanip>
#include <cstddef>

class PmergeMe {
    private:
        std::vector<long> _input;
        std::vector<long> _vectorResult;
        std::deque<long>  _dequeResult;
        double _vectorTime;
        double _dequeTime;

        std::vector<long> sortVector(std::vector<long> arr);
        std::deque<long>  sortDeque(std::deque<long> arr);
        std::vector<size_t> jacobsthalOrder(size_t count) const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void parseInput(int argc, char **argv);
        void runVectorSort();
        void runDequeSort();
        void printResults() const;
};

#endif
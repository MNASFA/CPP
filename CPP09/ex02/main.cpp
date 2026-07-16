#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv){
    if (argc < 2){
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe pmm;
    try {
        pmm.parseInput(argc, argv);
        pmm.runVectorSort();
        pmm.runDequeSort();
        pmm.printResults();
    }
    catch (const std::exception &e){
        (void) e;
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
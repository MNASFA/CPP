#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int ac, char **av)
{
    try 
    {
        PmergeMe p;
        p.parseInput(ac, av);
        p.runVectorSort();
        p.runDequeSort();
        p.printResults();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

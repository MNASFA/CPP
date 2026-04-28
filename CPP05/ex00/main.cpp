#include "Bureaucrat.hpp"

int main(){
    std::cout << "====== Test 1: Valid Bureaucrat Creation =======" << std::endl;
    try
    {
        Bureaucrat Test_1("Test 1", 0);
        std::cout << Test_1 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== Test 2: Grade too high =======" << std::endl;
    try
    {
        Bureaucrat Test_2("Test 2", 0);
        std::cout << Test_2 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== Test 2: Grade too low =======" << std::endl;
    try
    {
        Bureaucrat Test_3("Test 3", 151);
        std::cout << Test_3 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== Test 4: Grade Increment =======" << std::endl;
    try
    {
        Bureaucrat Test_4("Test 4", 150);
        Test_4.incrementGrade();
        std::cout << Test_4 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== Test 5: Grade Decrement =======" << std::endl;
    try
    {
        Bureaucrat TEST_5("Test 5", 1);
        TEST_5.decrementGrade();
        std::cout << TEST_5 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }
}


#include "Form.hpp"

int main(){
    std::cout << "====== Test 1: Valid Form Creation =======" << std::endl;
    try
    {
        Form formA("Form 1", 50, 25);
        std::cout << formA << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== Test 2: Form Grade too high =======" << std::endl;
    try
    {
        Form formA("Form 1", 0, 25);
        std::cout << formA << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== Test 3: Form Grade too low =======" << std::endl;
    try
    {
        Form formA("Form 1", 50, 151);
        std::cout << formA << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== Test 4: Success form signing =======" << std::endl;
    try
    {
        Bureaucrat houssam("Houssam", 30);
        Form formA("Report", 50, 25);
        houssam.signForm(formA);
        std::cout << formA << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "====== Test 5: Failed form signing =======" << std::endl;
    try
    {
        Bureaucrat houssam("Houssam", 30);
        Form formA("Report", 20, 25);
        houssam.signForm(formA);
        std::cout << formA << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

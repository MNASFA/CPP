
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
    
    std::srand(time(NULL));

    std::cout << "===== Test 1: ShrubberyCreationForm =====" << std::endl;
    try
    {
        Bureaucrat houssam("Houssam", 1);
        ShrubberyCreationForm test1("home");

        std::cout << test1 << std::endl;
        houssam.signForm(test1);
        houssam.executeForm(test1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "===== Test 2: PresidentialPardonForm =====" << std::endl;
    try
    {
        Bureaucrat anouar("Anouar", 1);
        PresidentialPardonForm test2("test2");

        std::cout << test2 << std::endl;
        anouar.signForm(test2);
        anouar.executeForm(test2);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "===== Test 2: PresidentialPardonForm =====" << std::endl;
    try
    {
        Bureaucrat hamza("Hamza", 1);
        RobotomyRequestForm test3("test3");

        std::cout << test3 << std::endl;
        hamza.signForm(test3);
        hamza.executeForm(test3);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    return 0;
}


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    std::cout << "===== Test 1: ShrubberyCreationForm =====" << std::endl;
    try
    {
        Bureaucrat houssam("Houssam", 150);
        ShrubberyCreationForm shrub("street");

        std::cout << shrub << std::endl;
        houssam.signForm(shrub);
        houssam.executeForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    
    return 0;
}

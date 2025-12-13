#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation", 145, 137), _target(target){
        std::cout << "ShrubberyCreationForm constructor called for target" << std::endl;
}


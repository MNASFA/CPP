#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation", 145, 137), _target(target){
        std::cout << "ShrubberyCreationForm constructor called for target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &other)
        this->operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destructor called for target " << _target  << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const{
    return this->_target;
}

void ShrubberyCreationForm::executeAction() const{
    std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cout << "Error : could not create file" << std::endl;
        return ;
    }
    // Ascii tree

}

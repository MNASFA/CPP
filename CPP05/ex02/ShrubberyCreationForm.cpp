#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", 145, 137), _target("Default"){
        std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation", 145, 137), _target(target){
        std::cout << "ShrubberyCreationForm constructor called for target " << _target << std::endl;
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

void ShrubberyCreationForm::executeAction() const{
    std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    std::cout << std::endl;

    if (!file.is_open())
    {
        std::cout << "Error : could not create file" << std::endl;
        return ;
    }
    
    file << "      oxoxoo    ooxooo      \n";
    file << "    ooxoxo oo  oxoxoooo     \n";  
    file << "   oooo xxoxoo ooo oooxo    \n"; 
    file << "   oxo o oxoxo  xoxxoxoo    \n"; 
    file << "    oxo xooxoooo o oooo     \n";
    file << "       ooo\\oo\\  /o/o      \n";
    file << "           \\  \\/ /        \n";
    file << "            |   /           \n";
    file << "            |  |            \n";
    file << "            | D|            \n";
    file << "            |  |            \n";
    file << "            |  |            \n";
    file << "     ______/____\\____        ";

    file.close();
    std::cout << "ASCII trees written to " << filename << std::endl;
    std::cout << std::endl;
}

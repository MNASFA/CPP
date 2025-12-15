#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
 : AForm("Robotomy Request", 72, 45), _target("Default"){
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
 : AForm("Robotomy Request", 72, 45), _target(target){
    std::cout << "RobotomyRequestForm constructor called for target " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
 : AForm(other), _target(other._target){
    std::cout << "RobotomyRequestForm copy constructor called for target " << _target << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    if (this != &other)
        this->operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::executeAction() const{
    std::cout << std::endl;

    std::cout << "*** VVVVVRRRRR... ZZZZ... ***" << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;

    std::cout << std::endl;
}

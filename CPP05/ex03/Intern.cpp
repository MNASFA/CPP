#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other){
    std::cout << "Intern Copy constructor called" << std::endl;
    (void) other;
}

Intern &Intern::operator=(const Intern &other){
    std::cout << "Intern Copy Assignment operator called" << std::endl;
    (void) other;
    return *this;
}

Intern::~Intern(){
    std::cout << "Intern Destructor called" << std::endl;
}

// Helper functions 

AForm *Intern::createShrubberyForm(std::string target){
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target){
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target){
    return new RobotomyRequestForm(target);
}

// Main makeForm Function

AForm *Intern::makeForm(std::string name, std::string target){
    std::string names[3] = {
        "shrubbery creation" ,
        "presidential pardon" ,
        "robotomy request"
    };

    AForm* (Intern::*forms[3])(std::string) = {
        &Intern::createShrubberyForm,
        &Intern::createPresidentialPardonForm,
        &Intern::createRobotomyRequestForm
    };

    for (int i = 0; i <= 2; i++){
        if (name == names[i]){
            std::cout << "Intern creates " << names[i] << std::endl;
            return (this->*forms[i])(target);
        }
    }

    std::cout << "Error : \"" << name << "\" not found , Intern cannot create this form" << std::endl;
    return NULL;
}

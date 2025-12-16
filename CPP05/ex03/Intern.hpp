#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        AForm *createShrubberyForm(std::string target);
        AForm *createPresidentialPardonForm(std::string target);
        AForm *createRobotomyRequestForm(std::string target);
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);
};


#endif
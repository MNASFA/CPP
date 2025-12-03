#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

        void validateGrade(int grade);

    public:
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned();

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
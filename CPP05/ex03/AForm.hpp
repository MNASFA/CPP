#ifndef AAForm_HPP
# define AAForm_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

        void validateGrade(int grade);

    protected:
        // Each concrete form implements its specific action
        virtual void executeAction() const = 0;

    public:
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;

        void beSigned(const Bureaucrat &bureaucrat);

        // Add in ex02
        void execute(Bureaucrat const &executor) const;

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

        // New Exception !

        class FormNotSignedException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
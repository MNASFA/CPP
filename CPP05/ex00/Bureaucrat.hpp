#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        std::string const name;
        int range;

        void validateGrade(int grade);
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int range);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName(void) const;
        int getGrade(void) const;

        void incrementGrade();
        void decrementGrade();

        

};

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &bureaucrat);

#endif
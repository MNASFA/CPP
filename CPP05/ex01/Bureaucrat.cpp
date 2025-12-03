#include "Bureaucrat.hpp"

void Bureaucrat::validateGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException(); 
}

Bureaucrat::Bureaucrat() : name("Default") , grade(150){
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name){
    validateGrade(_grade);
    this->grade = _grade;
    std::cout << "Bureaucrat " << this->name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) , grade(other.grade){
    std::cout << "Bureuacrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    if (this != &other){
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

void Bureaucrat::incrementGrade(){
    validateGrade(this->grade + 1);
    this->grade++;
    std::cout << "Grade is incremented" << std::endl;
}

void Bureaucrat::decrementGrade(){
    validateGrade(this->grade - 1);
    this->grade--;
    std::cout << "Grade is decremented" << std::endl;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

std::string Bureaucrat::getName() const{
    return this->name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too hight !! <Minimum is 1>" ;
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low !! <Maximum is 150>";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}
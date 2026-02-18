#include "Form.hpp"

void Form::validateGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) 
: _name(name), _isSigned(false) ,_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
    std::cout << "Form " << _name << " constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned)
, _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other){
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form(){
    std::cout << "Form Destructor called" << std::endl;
}

std::string Form::getName() const{
    return this->_name;
}

int Form::getGradeToSign() const{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const{
    return this->_gradeToExecute;
}

bool Form::isSigned(){
    return this->_isSigned;
}

void Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form){
    out << "Name : " << form.getName() << "\n" 
    << "Grade to sign : " << form.getGradeToSign() << "\n" 
    << "Grade to execute : " << form.getGradeToExecute();
    return out;
}

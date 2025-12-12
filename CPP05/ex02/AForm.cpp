#include "AForm.hpp"

void AForm::validateGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) 
: _name(name),_isSigned(false) ,_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
    std::cout << "AForm " << _name << " constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned)
, _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other){
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm(){
    std::cout << "AForm Destructor called" << std::endl;
}

// Getters 

std::string AForm::getName() const{
    return this->_name;
}

int AForm::getGradeToSign() const{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const{
    return this->_gradeToExecute;
}

bool AForm::isSigned(){
    return this->_isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "Form is not signed !!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form){
    out << "Name : " << form.getName() << "\n" << "Grade to sign : " << form.getGradeToSign()
    << "\n" << "Grade to execute : " << form.getGradeToExecute();
    return out;
}

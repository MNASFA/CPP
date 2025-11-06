#include "Fixed.hpp"

// Orthodox Canonical form

Fixed::Fixed(){
    fixedPointValue = 0;
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor is called" << std::endl;
}

void Fixed::setRawBits(int const raw){
    this->fixedPointValue = raw;
}

int Fixed::getRawBits(void) const{
    return (this->fixedPointValue);
}

// New constructors

Fixed::Fixed(const int nb){
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = nb * 256;
}

Fixed::Fixed(const float f){
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(f * 256);
}

float Fixed::toFloat(void) const{
    return ((float)this->getRawBits() / 256.0);
}

int Fixed::toInt(void) const{
    return (this->getRawBits() / 256);
}

std::ostream &operator<<(std::ostream &cout, Fixed const &obj){
    cout << obj.toFloat();
    return (cout);
}

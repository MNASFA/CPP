#include "Fixed.hpp"

// default constructor
Fixed::Fixed(){
    fixedPointValue = 0;
    std::cout << "Default Constructor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment constructor 
Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Destuctor 
Fixed::~Fixed(){
    std::cout << "Destructor si called" << std::endl;
}

// setter
void Fixed::setRawBits(int const raw){
    this->fixedPointValue = raw;
}

// getter
int Fixed::getRawBits(void) const{
    std::cout << "getRawsBits member function called" << std::endl;
    return (this->fixedPointValue);
}
#include "Fixed.hpp"

// Canonical form
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
    std::cout << "Destructor si called" << std::endl;
}

void Fixed::setRawBits(int const raw){
    this->fixedPointValue = raw;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawsBits member function called" << std::endl;
    return (this->fixedPointValue);
}


// New constructors
Fixed::Fixed(const int nb){
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = nb << fractionalBits;
}

Fixed::Fixed(const float f){
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(f * (1 << fractionalBits));
}

// ...
#include "Animal.hpp"

Animal::Animal(){
    this->type = "Default";
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string type){
    this->type = type;
    std::cout << "Animal Param constructor called" << std::endl;
}

Animal::Animal(const Animal &other){
    *this = other;
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
    std::cout << "Animal Copy assignement operator called" << std::endl;
    if (this != &other){
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::getType(void) const{
    return (this->type);
}

void Animal::makeSound() const{
    std::cout << "Animal " << this->type << " make a sound !" << std::endl;
}


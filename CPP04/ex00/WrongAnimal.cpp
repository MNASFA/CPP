#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    this->type = "Default";
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
    this->type = type;
    std::cout << "WrongAnimal Param constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    *this = other;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal Copy assignement operator called" << std::endl;
    if (this != &other){
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return (this->type);
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal " << this->type << " make a sound !" << std::endl;
}
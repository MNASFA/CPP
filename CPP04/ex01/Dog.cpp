#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy Assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof ! Woof !" << std::endl;
}

Brain *Dog::getBrain(void) const{
    return this->brain;
}

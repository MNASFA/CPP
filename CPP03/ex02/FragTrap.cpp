#include "FragTrap.hpp"

// Orthodox Canonical form

FragTrap::FragTrap() : ClapTrap(){
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " Constructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
    std::cout << "FragTrap copy assignement operator called" << std::endl;
    if (this != &other){
        ClapTrap::operator=(other);
    }
    return (*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << this->name << " request a positive high five !" << std::endl;
}
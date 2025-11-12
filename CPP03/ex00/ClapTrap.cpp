#include "ClapTrap.hpp"

// Orthodox Canonical form

ClapTrap::ClapTrap(){
    this->name = "Default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

    std::cout << "ClapTrap " << this->name << " Constructor is Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
    std::cout << "Copy Constructor called" << std::endl;

    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
    std::cout << "Copy Assignement operator called" << std::endl;
    if (this != &other){
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor Called" << std::endl;
}

// Methods implimentation

void ClapTrap::attack(const std::string &target){
    if (this->hitPoints == 0){
        std::cout << "ClapTrap " << this->name << " is dead and cannot attack" << std::endl;
        return ;
    }

    if (this->energyPoints == 0){
        std::cout << "ClapTrap " << this->name << " has no energy to attack" << std::endl;
        return ;
    }

    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target 
            << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->hitPoints == 0){
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
        return ;
    }

    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    
    std::cout << "ClapTrap " << this->name << " takes " << amount
            << " points of damage , Current HP: " << this->hitPoints << std::endl;

    if (this->hitPoints == 0){
        std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->hitPoints == 0){
        std::cout << "ClapTrap " << this->name << " is dead and cannot repair" << std::endl;
        return ;
    }

    if (this->energyPoints == 0){
        std::cout << "ClapTrap " << this->name << " has no energy to repair" << std::endl;
        return ;
    }

    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap" << this->name << " repairs itself for " << amount
                << " hit points! Current HP: " << hitPoints << std::endl;
}

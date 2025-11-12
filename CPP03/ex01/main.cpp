#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    ScavTrap scav1("Scav 1");
    ClapTrap clap1("Clap 1");

    std::cout << std::endl;

    scav1.attack("Enemy 1");
    clap1.attack("Enemy 2");

    std::cout << std::endl;

    scav1.takeDamage(4);
    clap1.takeDamage(4);
    scav1.beRepaired(6);
    clap1.beRepaired(6);
    scav1.takeDamage(15);
    clap1.takeDamage(15);

    std::cout << std::endl;

    scav1.guardGate();

    std::cout << std::endl;

    return 0;
}

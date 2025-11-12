#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Test 1");
    ClapTrap clap2("Test 2");

    std::cout << std::endl;

    clap1.attack("Enemy 1");
    clap2.attack("Enemy 2");

    std::cout << std::endl;

    clap1.takeDamage(4);
    clap2.takeDamage(5);

    std::cout << std::endl;

    clap1.beRepaired(6);
    clap2.beRepaired(3);

    std::cout << std::endl;

    clap1.takeDamage(15);

    std::cout << std::endl;

    return 0;
}
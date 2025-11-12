#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap clap1("CT-01");
    ClapTrap clap2("CT-02");

    std::cout << "\n=== Testing Attack ===" << std::endl;
    clap1.attack("Enemy");
    clap1.attack("Enemy");

    std::cout << "\n=== Testing Take Damage ===" << std::endl;
    clap2.takeDamage(5);
    clap2.takeDamage(3);

    std::cout << "\n=== Testing Repair ===" << std::endl;
    clap2.beRepaired(4);

    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    ClapTrap clap3("CT-03");
    for (int i = 0; i < 11; i++) {
        clap3.attack("Target");
    }

    std::cout << "\n=== Testing Death ===" << std::endl;
    ClapTrap clap4("CT-04");
    clap4.takeDamage(10);
    clap4.attack("Ghost");      // Should fail (no HP)
    clap4.beRepaired(5);        // Should fail (no HP)

    std::cout << "\n=== Destructors ===" << std::endl;
    return 0;
}
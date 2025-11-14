#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "             TESTING CLAPTRAP             " << std::endl;
    std::cout << "==========================================" << std::endl;
    ClapTrap clap("CLAP_1");
    clap.attack("TARGET_1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "==========================================" << std::endl;
    std::cout << "             TESTING SCAVTRAP             " << std::endl;
    std::cout << "==========================================" << std::endl;
    ScavTrap scav("SCAV_1");
    scav.attack("TARGET_2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "==========================================" << std::endl;
    std::cout << "            SCAVTRAP MORE TESTS           " << std::endl;
    std::cout << "==========================================" << std::endl;

    ScavTrap scav2("SCAV_2");
    for (int i = 0; i < 51; i++)
        scav2.attack("TARGET_3");
    
    std::cout << "==========================================" << std::endl;
    std::cout << "                 DESTRUCTORS              " << std::endl;
    std::cout << "==========================================" << std::endl;    
    
    return 0;
}

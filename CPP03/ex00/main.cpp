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
    std::cout << "            SCAVTRAP MORE TESTS           " << std::endl;
    std::cout << "==========================================" << std::endl;

    ClapTrap clap2("CLAP_2");
    for (int i = 0; i <= 10; i++)
        clap2.attack("TARGET_3");
    
    std::cout << "==========================================" << std::endl;
    std::cout << "                 DESTRUCTORS              " << std::endl;
    std::cout << "==========================================" << std::endl;    
    
    return 0;
}

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    std::cout << "             TESTING FRAGTRAP             " << std::endl;
    std::cout << "==========================================" << std::endl;
    FragTrap frag("FRAG_1");
    frag.attack("TARGET_3");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();
    
    std::cout << "==========================================" << std::endl;
    std::cout << "            FRAGTRAP MORE TESTS           " << std::endl;
    std::cout << "==========================================" << std::endl;
    FragTrap frag2("FRAG_2");
    std::cout << "\n* Testing 100 HP:" << std::endl;
    frag2.takeDamage(50);
    frag2.takeDamage(30);
    
    std::cout << "\n* Testing 100 attacks:" << std::endl;
    FragTrap frag3("FRAG_3");
    for (int i = 0; i <= 100; i++) {
            frag3.attack("TARGET_4");
    }
    
    std::cout << "==========================================" << std::endl;
    std::cout << "               DESTRUCTIONS               " << std::endl;
    std::cout << "==========================================" << std::endl;
    
    return 0;
}

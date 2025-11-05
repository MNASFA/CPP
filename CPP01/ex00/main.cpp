/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 09:01:09 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/31 19:29:47 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "== Testing randomChump (stack allocation) ==" << std::endl;
    randomChump("Stack Zombie");
    std::cout << "randomChump finished, Zombie destroyed" << std::endl;
    std::cout << std::endl;

    std::cout << "== Testing newZombie (heap allocation) ==" << std::endl;
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    std::cout << "Before deleting heapZombie" << std::endl;
    delete(heapZombie);
    std::cout << "heapZombie deleted" << std::endl;
    std::cout << std::endl;

    std::cout << "== Testing multiple newZombies ==" << std::endl;
    Zombie *Zombie1 = newZombie("Zombie 1");
    Zombie *Zombie2 = newZombie("Zombie 2");
    Zombie *Zombie3 = newZombie("Zombie 3");
    Zombie1->announce();
    Zombie2->announce();
    Zombie3->announce();
    std::cout << "Before deleting Zombies" << std::endl;
    delete(Zombie1);
    delete(Zombie2);
    delete(Zombie3);
    std::cout << "Zombies is deleted" << std::endl;
    std::cout << std::endl;
}

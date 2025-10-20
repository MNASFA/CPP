/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:10:29 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/20 14:22:35 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        std::cout << "=== HumanA Using Refrence ===" << std::endl;
        Weapon club = Weapon("Crude spiked club");
        
        std::cout << std::endl;

        HumanA bob("Bob", club);
        bob.attacks();
        club.setType("Some other type of club");
        bob.attacks();

        std::cout << std::endl;   
    }

    {
        std::cout << "=== HumanB Using Pointer ===" << std::endl;
        Weapon club = Weapon("Crude spiked club");
        
        std::cout << std::endl;

        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attacks();
        club.setType("Some other type of club");
        jim.attacks();
        
        std::cout << std::endl;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:10:29 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/11/01 10:14:00 by marvin           ###   ########.fr       */
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
        // jim.setWeapon(club);
        jim.attacks();
        jim.setWeapon(club);
        club.setType("Some other type of club");
        jim.attacks();
        
        std::cout << std::endl;
    }
}
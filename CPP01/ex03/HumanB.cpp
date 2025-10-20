/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:15:21 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/20 14:17:29 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}

void HumanB::attacks()
{
    if (this->weapon == NULL)
    {
        std::cout << this->name << " has no weapon !!" << std::endl;
        return ;
    }
    std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
}

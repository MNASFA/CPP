/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:31:36 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/20 14:18:09 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
	this->type = "";
}

Weapon::~Weapon(){}

Weapon::Weapon(std::string type){
	this->type = type;
}

void Weapon::setType(std::string type){
	this->type = type;
}

const std::string &Weapon::getType(){
	return (this->type);
}

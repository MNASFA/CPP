/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:20:02 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/11/04 17:31:02 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void){
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "This is a debug !!" << std::endl;
}

void Harl::info(void){
    std::cout << "[INFO]" << std::endl;
    std::cout << "This is a info !!" << std::endl;
}

void Harl::warning(void){
    std::cout << "[WARNING]" << std::endl;
    std::cout << "This is a warning !!" << std::endl;
}

void Harl::error(void){
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is a error !!" << std::endl;
}

int getLevelIndex(std::string &level)
{
    if (level == "DEBUG")
        return 0;
    if (level == "INFO")
        return 1;
    if (level == "WARNING")
        return 2;
    if (level == "ERROR")
        return 3;
    return (-1);
}

void Harl::complain(std::string level){
    int index = getLevelIndex(level);
    
    switch (index)
    {
        case 0:
            this->debug();
            break;
        case 1:
            this->info();
            break;
        case 2:
            this->warning();
            break;
        case 3:
            this->error();
            break;
        default:
            std::cout << "Insignificant problems !!!" << std::endl;
            break;
    }
    std::cout << std::endl;
}

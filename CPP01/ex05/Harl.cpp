/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:19:36 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/11/01 11:19:37 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "=== Harl has ready to complain ===" << std::endl;
}

Harl::~Harl(){
    std::cout << "=== Harl has stopped complaining ===" << std::endl;
}

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

void Harl::complain(std::string level){
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[4])(void) = {
        &Harl::debug ,
        &Harl::info ,
        &Harl::warning ,
        &Harl::error
    };

    for (int i = 0; i <= 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
    }

    std::cout << "Insignificant problems !!!" << std::endl;
    std::cout << std::endl;
}

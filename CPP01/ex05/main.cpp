/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:19:45 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/11/01 11:19:46 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << std::endl;
    harl.complain("DEBUG");

    std::cout << std::endl;
    harl.complain("INFO");

    std::cout << std::endl;
    harl.complain("WARNING");

    std::cout << std::endl;
    harl.complain("ERROR");

    std::cout << std::endl;
    harl.complain("TEST");
}
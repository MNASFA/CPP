/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:15 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 11:30:31 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> numbers(5);
    for (int i = 0; i < 5; i++){
        numbers.at(i) = i;
    }
    
    try
    {
        std::vector<int>::iterator it = ::easyfind(numbers, 3);
        std::cout << "Number is : " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: projects_1337 <projects_1337@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:15 by hmnasfa           #+#    #+#             */
/*   Updated: 2026/07/12 02:20:17 by projects_13      ###   ########.fr       */
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
        std::vector<int>::iterator it = easyfind(numbers, 10);
        std::cout << "Number is : " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}


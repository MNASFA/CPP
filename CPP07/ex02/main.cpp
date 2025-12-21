/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:42 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 09:37:43 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() 
{
    Array<int> arr(3);

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    std::cout << "Array size: " << arr.size() << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
    }

    try {
        std::cout << "Accessing out of bounds..." << std::endl;
        arr[3] = 0;
        std::cout << "Dooone!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    return 0;
}

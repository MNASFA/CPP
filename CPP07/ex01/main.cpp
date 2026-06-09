/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:48 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 09:37:49 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "iostream"

void printInt(const int &n) {
    std::cout << n << " ";
}

void increment(int &n){
    n++;
}

int main(){
    int array[] = {1, 2, 3, 4, 5};
    size_t lenght = 5;

    std::cout << "=== Before increment values ===" << std::endl;
    std::cout << "Array Content : ";
    ::iter(array, lenght, printInt);
    std::cout << std::endl;

    std::cout << "=== After increment values ===" << std::endl;
    ::iter(array, lenght, increment);
    std::cout << "Array Content : ";
    ::iter(array, lenght, printInt);
    std::cout << std::endl;

    const int constArr[] = {10, 20, 30, 40, 50};

    std::cout << "=== Const array ===" << std::endl;
    std::cout << "Array Content : ";
    ::iter(constArr, 5, printInt); 
    std::cout << std::endl;

    return 0;
}

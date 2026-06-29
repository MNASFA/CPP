/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: projects_1337 <projects_1337@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:48 by hmnasfa           #+#    #+#             */
/*   Updated: 2026/06/29 02:55:11 by projects_13      ###   ########.fr       */
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
    iter(array, lenght, printInt);
    std::cout << std::endl;

    std::cout << "=== After increment values ===" << std::endl;
    iter(array, lenght, increment);
    std::cout << "Array Content : ";
    iter(array, lenght, printInt);
    std::cout << std::endl;

    const int constArr[] = {10, 20, 30, 40, 50};

    std::cout << "=== Const array ===" << std::endl;
    std::cout << "Array Content : ";
    iter(constArr, 5, printInt); 
    std::cout << std::endl;

    return 0;
}

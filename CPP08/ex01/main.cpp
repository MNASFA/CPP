/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: projects_1337 <projects_1337@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:26:10 by hmnasfa           #+#    #+#             */
/*   Updated: 2026/07/12 03:23:52 by projects_13      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {

        std::cout << "========================== Testing 5 element ================================" << std::endl;
        std::cout << std::endl;    
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << std::endl;
        std::cout << "========================== Testing multiple element ================================" << std::endl;
        std::cout << std::endl;
        
        Span span(11);
        std::vector<int> bigVector;

        span.addNumber(2);
        
        for (int i = 0; i < 10; i++)
            bigVector.push_back(i);

        span.addNumbers(bigVector.begin(), bigVector.end());
        std::cout << span.shortestSpan() << std::endl;
        std::cout << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:26:10 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 14:18:38 by hmnasfa          ###   ########.fr       */
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
        std::cout << "========================== Testing 10000 element ================================" << std::endl;
        std::cout << std::endl;
        
        Span span(10000);
        std::vector<int> bigVector;
        
        for (int i = 0; i < 10000; i++)
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
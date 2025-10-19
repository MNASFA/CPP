/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:34:12 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/19 15:44:10 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "=== Memory Adresses ===" << std::endl;
	std::cout << "The memory address of str " << &str << std::endl;
	std::cout << "The memory address held by stringPTR " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF " << &stringREF << std::endl;
	
	std::cout << std::endl;

	std::cout << "=== Values ===" << std::endl;
	std::cout << "The Value of str " << str << std::endl;
	std::cout << "The Value pointed to by stringPTR " << *stringPTR << std::endl;
	std::cout << "The Value pointed to by stringREF " << stringREF << std::endl;
}
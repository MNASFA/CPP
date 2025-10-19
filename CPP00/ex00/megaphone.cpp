/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:45:02 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/19 10:21:23 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        size_t j = 0;
        while (j < str.length())
        {
            str[j] = toupper(str[j]);
            j++;
        }
        std::cout << str;
    }
    std::cout << std::endl; return 0;
}

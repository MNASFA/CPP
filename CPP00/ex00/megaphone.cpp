/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:45:02 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/16 20:28:34 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return (1);
    }
    
    for (int i = 1; i < ac; i++)
    {
        string str = av[i];
        size_t j = 0;
        while (j < str.length())
        {
            str[j] = toupper(str[j]);
            j++;
        }
        cout << str;
    }
    cout << endl;
    return 0;
}

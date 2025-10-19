/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:17:48 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/10/19 14:26:14 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 10;
	
	std::cout << "== Create a horde of " << N << " zombies ==" << std::endl;
	Zombie *horde = zombieHorde(N, "Zombie");
	std::cout << std::endl;

	std::cout << "== Each zombie anounce ==" << std::endl;
	for (int i = 0; i < N; i++)
	{
		horde[i].anounce();
	}
	std::cout << std::endl;

	std::cout << "== Deleting all zombies ==" << std::endl;
	delete[] horde;
	std::cout << std::endl;
	std::cout << "Horde deleted" << std::endl;
	
}
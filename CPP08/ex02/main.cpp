/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:08:10 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/22 13:08:26 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main(){

    std::cout << "------------------MUTANTSTACK TEST------------------" << std::endl;
    std::cout << std::endl;
    // ========== MutantStack Version ==========
    MutantStack<int> mstack;
    mstack.push(5);           // Add to stack
    mstack.push(17);
    std::cout << mstack.top();    // Access top
    mstack.pop();             // Remove from top
    std::cout << mstack.size();   // Size
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << std::endl;
    std::cout << "------------------STD::LIST TEST------------------" << std::endl;
    std::cout << std::endl;

    std::list<int> list;
    list.push_back(5);        // Add to back
    list.push_back(17);
    std::cout << list.back(); // Access back (like top)
    list.pop_back();          // Remove from back
    std::cout << list.size(); // Size
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator it1 = list.begin();
    std::list<int>::iterator ite1 = list.end();
    ++it;
    --it;
    while (it1 != ite1) {
        std::cout << *it1 << std::endl;
        ++it1;
    }

    return 0;
}

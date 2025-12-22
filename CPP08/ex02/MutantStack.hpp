/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:08:13 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/22 13:08:14 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include "iostream"
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> 
{
    public:
        MutantStack() : std::stack<T>(){}
        MutantStack(const MutantStack &other) : std::stack<T>(other){}
        MutantStack<T> &operator=(const MutantStack<T> &other){
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack();

        std::deque<T>::iterator begin(){
            return (this->c.begin());
        }
        
        std::deque<T>::iterator end(){
            return (this->c.end());
        }
};

#endif
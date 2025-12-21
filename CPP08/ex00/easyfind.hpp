/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:09 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 11:03:12 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <iostream>

class EasyFindException : public std::exception{
    public:
        virtual const char *what() const throw(){
            return "Exception : Easy Find Exception!";
        }         
};

template <typename T>
typename T::iterator easyfind(T &container, int n){
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if ( it == container.end())
        throw EasyFindException();
    return it;
}

#endif
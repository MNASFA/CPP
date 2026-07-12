/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: projects_1337 <projects_1337@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:09 by hmnasfa           #+#    #+#             */
/*   Updated: 2026/07/12 02:08:27 by projects_13      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>
#include <iostream>

class EasyFindException : public std::exception{
    public:
        const char *what() const throw(){
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
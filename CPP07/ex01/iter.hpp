/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: projects_1337 <projects_1337@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:51 by hmnasfa           #+#    #+#             */
/*   Updated: 2026/06/29 02:53:05 by projects_13      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t lenght, F func){
    if (!array)
        return;
    for (size_t i = 0; i < lenght; i++){
        func(array[i]);
    }
}

#endif
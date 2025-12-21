/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:51 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 09:37:52 by hmnasfa          ###   ########.fr       */
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
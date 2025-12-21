/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:38:01 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 09:38:02 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T &a, T &b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(T &a, T &b){
    if (a > b)
        return a;
    else
        return b;
}

#endif
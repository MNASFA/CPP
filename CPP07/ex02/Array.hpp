/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:37:38 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 09:37:39 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int arr_size;
    public:
        Array() : elements(NULL), arr_size(0) {}

        Array(unsigned int n) : elements(NULL), arr_size(n){
            if (n > 0){
                elements = new T[n]();
            }
        }

        Array(const Array &other) : elements(NULL), arr_size(other.arr_size){
            if (arr_size > 0){
                elements = new T[arr_size];
                for (unsigned int i = 0; i < arr_size; i++){
                    elements[i] = other.elements[i];
                }
            }
        }

        Array &operator=(const Array &other){
            if (this != &other){
                delete[] elements;

                arr_size = other.arr_size;
                if (arr_size > 0){
                    elements = new T[arr_size];
                    for (unsigned int i = 0; i < arr_size; i++){
                        elements[i] = other.elements[i];
                    }
                } else
                    elements = NULL;
            }
            return *this;
        }

        ~Array() {
            delete[] elements;
        }

        T& operator[](unsigned int index){
            if (index >= arr_size)
                throw std::exception();
            return elements[index];
        }

        const T& operator[](unsigned int index) const{
            if (index >= arr_size)
                throw std::exception();
            return elements[index];
        }

        unsigned int size(){
            return arr_size;
        }
};

#endif

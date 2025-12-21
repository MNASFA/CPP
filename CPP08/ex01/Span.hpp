/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:33:35 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 13:46:28 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <exception>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        

        class MaxValueException : public std::exception{
            public:
                virtual const char *what() const throw();
        };

        class LessThanTwoException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
};

#endif
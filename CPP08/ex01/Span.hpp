/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: projects_1337 <projects_1337@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:33:35 by hmnasfa           #+#    #+#             */
/*   Updated: 2026/07/12 03:00:40 by projects_13      ###   ########.fr       */
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
        
        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end) {
            if (std::distance(begin, end) + numbers.size() > this->N)
                throw SpanFullException();
            numbers.insert(numbers.end(), begin, end);
        }
        
        unsigned int shortestSpan();
        unsigned int longestSpan();
        

        class SpanFullException : public std::exception{
            public:
                const char *what() const throw();
        };

        class LessThanTwoException : public std::exception{
            public:
                const char *what() const throw();
        };
};

#endif
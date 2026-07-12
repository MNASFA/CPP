/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: projects_1337 <projects_1337@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:40:30 by hmnasfa           #+#    #+#             */
/*   Updated: 2026/07/12 03:08:51 by projects_13      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0){}

Span::Span(unsigned int N) : N(N){}

Span::Span(const Span &other){
    this->numbers = other.numbers;
    this->N = other.N; 
}

Span &Span::operator=(const Span &other){
    if (this != &other)
    {
        this->numbers = other.numbers;
        this->N = other.N;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number){
    if (numbers.size() >= this->N)
        throw SpanFullException();
    numbers.push_back(number);
}

unsigned int Span::longestSpan(){
    if (numbers.size() < 2)
        throw LessThanTwoException();
        
    std::vector<int>::iterator min = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::iterator max = std::max_element(numbers.begin(), numbers.end());
    
    return (*max - *min);
}

unsigned int Span::shortestSpan(){
    if (numbers.size() < 2)
        throw LessThanTwoException();
    
    unsigned int min_distance = UINT_MAX;
    std::vector<int> tmp = numbers;
    std::sort(tmp.begin(), tmp.end());
    for (size_t i = 0; i < tmp.size() - 1 ; i++) {
        unsigned int mindiff = static_cast<int>(tmp[i + 1]) - static_cast<int>(tmp[i]);
        if (mindiff < min_distance)
            min_distance = mindiff;
    }
    return min_distance;
}

const char *Span::SpanFullException::what() const throw(){
    return "Exception: The number is greater than max!";
}

const char *Span::LessThanTwoException::what() const throw(){
    return "Exception: Less than two numbers!";
}

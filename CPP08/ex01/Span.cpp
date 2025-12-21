/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:40:30 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/12/21 14:05:25 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N){
    this->N = N;
}

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
    if (numbers.size() > this->N)
        throw MaxValueException();
    numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    unsigned int range = (*end - *begin) + numbers.size();
    if (range > this->N)
        throw MaxValueException();
    else
        numbers.insert(numbers.end(), begin, end);
}

int Span::longestSpan(){
    if (numbers.size() < 2)
        throw LessThanTwoException();
        
    std::vector<int>::iterator min = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::iterator max = std::max_element(numbers.begin(), numbers.end());
    
    return (*max - *min);
}

int Span::shortestSpan(){
    if (numbers.size() < 2)
        throw LessThanTwoException();
    
    unsigned int min_distance = UINT_MAX;
    std::vector<int> tmp = numbers;
    std::sort(tmp.begin(), tmp.end());
    for (size_t i = 0; i < tmp.size() - 1 ; i++) {
        unsigned int mindiff = tmp[i + 1] - tmp[i];
        if (mindiff < min_distance)
            min_distance = mindiff;
    }   
    return min_distance;
}

const char *Span::MaxValueException::what() const throw(){
    return "Exception: The number is greater than max!";
}

const char *Span::LessThanTwoException::what() const throw(){
    return "Exception: Less than two numbers!";
}

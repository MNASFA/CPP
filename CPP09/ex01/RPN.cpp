#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

RPN::RPN(){}

RPN::RPN(const RPN &other){
    (void) other;
}

RPN &RPN::operator=(const RPN &other){
    (void) other;
    return *this;
}

RPN::~RPN(){};

bool RPN::isOperator(const std::string &token) const{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string &token) const{
    if (token.empty())
        return false;
    for (size_t i = 0; i < token.length(); i++){
        if (!std::isdigit(token[i]))
            return false;
    }
    return true;
}

double RPN::applyOperator(double a, double b, char op) const{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) 
                throw std::runtime_error("Error");
            return a / b;
        default:
            throw std::runtime_error("Error");
    }
}

double RPN::evaluate(const std::string &expression){
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {   
        if (isNumber(token)){
            if (token.length() > 1)
                throw std::runtime_error("Error");
            stack.push(std::atoi(token.c_str()));
        }
        else if (isOperator(token)){
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            stack.push(applyOperator(a, b, token[0]));
        }
        else
            throw std::runtime_error("Error");
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error");

    double result = stack.top();
    stack.pop();
    return result;
}

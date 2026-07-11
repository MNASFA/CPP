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
        if (!std::isdigit(static_cast<unsigned char>(token[i])))
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
                throw std::runtime_error("division by zero");
            return a / b;
        default:
            throw std::runtime_error("unknown operator");
    }
}

double RPN::evaluate(const std::string &expression){
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {   
        if (isNumber(token)){
            if (token.length() > 1)
                throw std::runtime_error("invalid number");
            _stack.push(std::atof(token.c_str()));
        }
        else if (isOperator(token)){
            if (_stack.size() < 2)
                throw std::runtime_error("insufficient operands");
            double b = _stack.top();
            _stack.pop();
            double a = _stack.top();
            _stack.pop();
            _stack.push(applyOperator(a, b, token[0]));
        }
        else
            throw std::runtime_error("invalid token");
    }

    if (_stack.size() != 1)
        throw std::runtime_error("invalid expression");

    double result = _stack.top();
    _stack.pop();
    return result;
}

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>

enum literalType {
    CHAR,           
    INT,            
    FLOAT,          
    DOUBLE,
    FLOAT_PS,
    DOUBLE_PS,
    INVALID   
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

    public:
        static void convert(const std::string &literal);
};
#endif
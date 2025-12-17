#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <cctype>

class ScalarConverter
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        // Helper methods to detect type 
        static bool isChar(const std::string &leteral);
        static bool isInt(const std::string &leteral);
        static bool isFloat(const std::string &leteral);
        static bool isDouble(const std::string &leteral);
        static bool isPseudoLiteral(const std::string &leteral);

        // Helper methods for conversion
        static void convertFromChar(char c);
        static void converFromInt(int i);
        // static void convertFromFloat(float f);
        // static void convertFromDouble(double d);
        // static void handlePseudoLiteral(std::string &literal);

        // Display helper
        static void displayChar(char c, bool impossible);
        static void displayInt(int i, bool impossible);
        static void displayFloat(float f, bool impossible);
        static void displayDouble(double d, bool impossible);

    public:
        static void convert(const std::string &literal);
};


#endif
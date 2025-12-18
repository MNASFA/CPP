#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void) other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void) other;
    return *this;
}
ScalarConverter::~ScalarConverter(){};

void printValues(double d, const std::string& input)
{
    std::cout << "char: ";
    if (input == "nan" || input == "nanf" || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (input == "nan" || input == "nanf" || d > INT_MAX || d < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
    double d;
    char *end;

    if (input.length() == 1 && !std::isdigit(input[0])) {
        d = static_cast<double>(input[0]);
    }
    else {
        d = std::strtod(input.c_str(), &end);
        if (*end == 'f' && *(end + 1) != '\0') {
            std::cout << "Invalid Input" << std::endl;
            return ;
        }
        else if (*end != '\0' && *end != 'f') {
            std::cout << "Invalid Input" << std::endl;
            return ;
        }
    }
    printValues(d, input);
}

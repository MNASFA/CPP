#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

e_type detectType(const std::string& input) {
    if (input == "nan" || input == "inf" || input == "+inf" || input == "-inf")
        return DOUBLE_PS;
    if (input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
        return FLOAT_PS;

    if (input.length() == 1 && !std::isdigit(input[0]))
        return CHAR;

    char* endptr;
    double val = std::strtod(input.c_str(), &endptr);
    if (*endptr == '\0') {
        if (input.find('.') == std::string::npos && val >= INT_MIN && val <= INT_MAX)
            return INT;
        return DOUBLE;
    }
    if (*endptr == 'f' && *(endptr + 1) == '\0')
        return FLOAT;
    return INVALID;
}

void print_all(int i, char c, float f, double d, bool possible, const std::string& input) {
    bool isPseudo = (input == "nanf" || input == "inff" || input == "+inff" || input == "-inff" || 
                     input == "nan" || input == "inf" || input == "+inf" || input == "-inf");

    std::cout << "char: ";
    if (!possible || isPseudo || std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    std::cout << "int: ";
    if (!possible || isPseudo || std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& input) {
    if (input.empty()) {
        std::cout << "Error: empty literal" << std::endl;
        return;
    }

    e_type type = detectType(input);
    
    int i = 0;
    char c = 0;
    float f = 0.0f;
    double d = 0.0;

   if (type == CHAR) {
        c = input[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } 
    else if (type == INT) {
        i = std::atoi(input.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    } 
    else if (type == FLOAT) {
        errno = 0;
        f = static_cast<float>(std::strtod(input.c_str(), NULL));
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        if (std::isinf(f))
            d = std::strtod(input.c_str(), NULL);
        else
            d = static_cast<double>(f);
    } 
    else if (type == DOUBLE) {
        d = std::strtod(input.c_str(), NULL);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    } 
    else if (type == FLOAT_PS) {
        if (input == "nanf") 
            f = std::numeric_limits<float>::quiet_NaN();
        else if (input == "-inff") 
            f = -std::numeric_limits<float>::infinity();
        else 
            f = std::numeric_limits<float>::infinity();
        
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    } 
    else if (type == DOUBLE_PS) {
        if (input == "nan") 
            d = std::numeric_limits<double>::quiet_NaN();
        else if (input == "-inf") 
            d = -std::numeric_limits<double>::infinity();
        else 
            d = std::numeric_limits<double>::infinity();

        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    } 
    else {
        std::cout << "Error: Invalid literal format" << std::endl;
        return;
    }

    print_all(i, c, f, d, true, input);
}

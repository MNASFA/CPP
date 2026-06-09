#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

literalType checkPseudoLiteral(const std::string& literal) {
    if (literal == "nan"  || literal == "inf"
     ||  literal == "+inf" || literal == "-inf")
        return DOUBLE_PS;
    if (literal == "nanf" || literal == "inff"
     ||  literal == "+inff"|| literal == "-inff")
        return FLOAT_PS;
    return INVALID;
}

literalType getType(const std::string& literal) {
    literalType pseudo = checkPseudoLiteral(literal);
    if (pseudo != INVALID)
        return pseudo;

    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return CHAR;

    char* position;
    double val = std::strtod(literal.c_str(), &position);
    if (*position == '\0') {
        if (literal.find('.') == std::string::npos && val >= INT_MIN && val <= INT_MAX)
            return INT;
        return DOUBLE;
    }
    if (*position == 'f' && *(position + 1) == '\0')
        return FLOAT;
    return INVALID;
}

bool isPseudoLiteral(const std::string& literal) {
    return literal == "nan"  || literal == "+nan"  || literal == "-nan"  ||
           literal == "nanf" || literal == "+nanf" || literal == "-nanf" ||
           literal == "inf"  || literal == "+inf"  || literal == "-inf"  ||
           literal == "inff" || literal == "+inff" || literal == "-inff";
}

void displayResult(const std::string& literal, int i, char c, float f, double d) {
    bool isPseudo = isPseudoLiteral(literal);

    std::cout << "char: ";
    if (isPseudo || std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    std::cout << "int: ";
    if (isPseudo || std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: empty literal" << std::endl;
        return;
    }

    literalType type = getType(literal);
    
    int i = 0;
    char c = 0;
    float f = 0.0f;
    double d = 0.0;

   if (type == CHAR) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } 
    else if (type == INT) {
        i = std::atoi(literal.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    } 
    else if (type == FLOAT) {
        f = static_cast<float>(std::strtod(literal.c_str(), NULL));
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        if (std::isinf(f))
            d = std::strtod(literal.c_str(), NULL);
        else
            d = static_cast<double>(f);
    } 
    else if (type == DOUBLE) {
        d = std::strtod(literal.c_str(), NULL);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    } 
    else if (type == FLOAT_PS) {
        if (literal == "nanf") 
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "-inff") 
            f = -std::numeric_limits<float>::infinity();
        else 
            f = std::numeric_limits<float>::infinity();
        
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    } 
    else if (type == DOUBLE_PS) {
        if (literal == "nan") 
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "-inf") 
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

    displayResult(literal, i, c, f, d);
}

#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void) other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void) other;
    return *this;
}
ScalarConverter::~ScalarConverter(){};

bool isChar(const std::string &literal){
    return (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9'));
}

bool isInt(const std::string &literal){
    if (literal.empty())
        return false;

    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i >= literal.length())
        return false;
    while (i < literal.length()){
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

static bool isDecimal(const std::string &s) {
    if (s.empty()) return false;
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    bool hasDot = false, hasDigit = false;
    while (i < s.length()) {
        if (s[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (std::isdigit(s[i]))
            hasDigit = true;
        else
            return false;
        i++;
    }
    return hasDot && hasDigit;
}

bool isFloat(const std::string &literal) {
    if (literal.empty() || literal[literal.length() - 1] != 'f') 
        return false;
    return isDecimal(literal.substr(0, literal.length() - 1));
}

bool isDouble(const std::string &literal) {
    return isDecimal(literal);
}

bool isPseudoLiteral(const std::string &literal){
    if (literal == "nan" || literal == "nanf")
        return true;
    
    if (literal == "inf" || literal == "inff" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff")
            return true;

    return false;
}

// displaying

void displayChar(char c, bool impossible){
    std::cout << "char : ";
    if (impossible)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

void displayInt(int i, bool impossible){
    std::cout << "int : ";
    if (impossible)
        std::cout << "impossible";
    else
        std::cout << i;
    std::cout << std::endl;
}

void displayFloat(float f, bool impossible){
    std::cout << "float : ";
    if (impossible)
        std::cout << "impossible";
    else{
        std::cout << std::fixed << std::setprecision(1) << f;
        std::cout << "f";
    }
    std::cout << std::endl;
}

void displayDouble(double d, bool impossible){
    std::cout << "double : ";
    if (impossible)
        std::cout << "impossible";
    else{
        std::cout << std::fixed << std::setprecision(1) << d;
    }
    std::cout << std::endl;
}

// Convertion methods

void convertFromChar(char c){
    displayChar(c, false);
    displayInt(static_cast<int>(c), false);
    displayFloat(static_cast<float>(c), false);
    displayDouble(static_cast<double>(c), false);
}

void convertFromInt(int i){
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        displayChar(0, true);
    else
        displayChar(static_cast<char>(i), false);

    displayInt(i, false);
    displayFloat(static_cast<float>(i), false);
    displayDouble(static_cast<double>(i), false);
}

void convertFromFloat(float f){
    if (std::isnan(f) || std::isinf(f) 
        || f < std::numeric_limits<char>::min() 
        || f > std::numeric_limits<char>::max())
        displayChar(0, true);
    else
        displayChar(static_cast<char>(f), false);

    if (std::isnan(f) || std::isinf(f) 
        || f < std::numeric_limits<int>::min() 
        || f > std::numeric_limits<int>::max())
        displayInt(0, true);
    else
        displayInt(static_cast<int>(f), false);

    displayFloat(f, false);

    displayDouble(static_cast<double>(f), false);
}

void convertFromDouble(double d){
    if (std::isnan(d) || std::isinf(d) 
        || d < std::numeric_limits<char>::min() 
        || d > std::numeric_limits<char>::max())
        displayChar(0, true);
    else
        displayChar(static_cast<char>(d), false);

    if (std::isnan(d) || std::isinf(d) 
        || d < std::numeric_limits<int>::min() 
        || d > std::numeric_limits<int>::max())
        displayInt(0, true);
    else
        displayInt(static_cast<int>(d), false);

    float float_imp = static_cast<float>(d);
    if (d > std::numeric_limits<float>::max())
        displayFloat(0, true);
    else
        displayFloat(float_imp, false);

    if (d > std::numeric_limits<double>::max())
        displayDouble(0, true);
    else
        displayDouble(d, false);
}

void handlePseudoLiteral(const std::string &literal){
    double d;
    float f;
    if (literal == "nan" || literal == "nanf"){
        d = std::numeric_limits<double>::quiet_NaN();
        f = std::numeric_limits<float>::quiet_NaN();
    }
    else if (literal == "inf" || literal == "inff" ||
             literal == "+inf" || literal == "+inff" ){
        d = std::numeric_limits<double>::infinity();
        f = std::numeric_limits<float>::infinity();
    }else {
        d = -std::numeric_limits<double>::infinity();
        f = -std::numeric_limits<float>::infinity();
    }

    displayChar(0, true);
    displayInt(0 , true);
    displayFloat(f, false);
    displayDouble(d, false);
}

void ScalarConverter::convert(const std::string &literal){
    if (literal.empty()){
        std::cout << "Error : empty literal" << std::endl;
        return;
    }

    if (isPseudoLiteral(literal))
    {
        handlePseudoLiteral(literal);
        return ;
    }

    if (isChar(literal))
    {
        convertFromChar(literal[0]);
        return ;
    }

    if (isInt(literal)){
        errno = 0;
        long tmp = std::strtol(literal.c_str(), NULL, 10);
        // if (errno == ERANGE)
        // {
        //     errno = 0;
        //     double d = std::strtod(literal.c_str(), NULL);
        //     if (errno == ERANGE) {
        //         std::cout << "Error : number overflow" << std::endl;
        //         return;
        //     }
        //     convertFromDouble(d);
        //     return;
        // }
        if (errno == ERANGE || tmp < std::numeric_limits<int>::min() 
            || tmp > std::numeric_limits<int>::max())
        {
            convertFromDouble(std::strtod(literal.c_str(), NULL));
            return;
        }
        convertFromInt(static_cast<int>(tmp));
        return;
    }

    if (isFloat(literal)){
        errno = 0;
        double d = std::strtod(literal.c_str(), NULL);
        if (std::abs(d) > std::numeric_limits<float>::max())
            convertFromDouble(d);
        else
            convertFromFloat(static_cast<float>(d));
        return ;
    }

    if (isDouble(literal)){
        errno = 0;
        double d = std::strtod(literal.c_str(), NULL);
        convertFromDouble(d);
        return ;
    }
    std::cout << "Error : Invalid literal format" << std::endl;
}

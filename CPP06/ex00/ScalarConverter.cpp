#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void) other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void) other;
    return *this;
}
ScalarConverter::~ScalarConverter(){};

// Type detection 
bool ScalarConverter::isChar(const std::string &literal){
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string &literal){
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

bool ScalarConverter::isFloat(const std::string &literal){
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    std::string without_f = literal.substr(0, literal.length() - 1);
    size_t i = 0;
    if (without_f[i] == '+' || without_f[i] == '-')
        i++;
    bool hasDot = false;
    bool hasDigit = false;

    while (i < without_f.length()){
        if (without_f[i] == '.'){
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(without_f[i]))
            hasDigit = true;
        else
            return false;
        i++;
    }
    return hasDot && hasDigit;
}

bool ScalarConverter::isDouble(const std::string &literal){
    if (literal.empty())
        return false;
    
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    bool hasDot = false;
    bool hasDigit = false;

    while (i < literal.length())
    {
        if (literal[i] == '.'){
            if (hasDot)
                return false;
            hasDot = true;
        } else if (std::isdigit(literal[i]))
            hasDigit = true;
        else
            return false;
        i++;
    }
    return hasDot && hasDigit;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal){
    return (literal == "nan" || literal == "nanf" || 
            literal == "+inf" || literal == "-inf" ||
            literal == "+inff" || literal == "-inff" ||
            literal == "inf" || literal == "inff");
}

// Display methods

void ScalarConverter::displayChar(char c, bool impossible){
    std::cout << "char : ";
    if (impossible)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "Non diplayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

void ScalarConverter::displayInt(int i, bool impossible){
    std::cout << "int : ";
    if (impossible)
        std::cout << "impossible";
    else
        std::cout << i;
    std::cout << std::endl;
}

void ScalarConverter::displayFloat(float f, bool impossible){
    std::cout << "float : ";
    if (impossible)
        std::cout << "impossible";
    else{
        std::cout << f;
        if (std::isfinite(f) && f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::displayDouble(double d, bool impossible){
    std::cout << "double : ";
    if (impossible)
        std::cout << "impossible";
    else{
        std::cout << d;
        if (std::isfinite(d) && d == static_cast<int>(d))
            std::cout << ".0";
    }
    std::cout << std::endl;
}

// Convertion methods

void ScalarConverter::convertFromChar(char c){
    displayChar(c, false);
    displayInt(static_cast<int>(c), false);
    displayFloat(static_cast<float>(c), false);
    displayDouble(static_cast<double>(c), false);
}

void ScalarConverter::converFromInt(int i){
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        displayChar(0, true);
    else
        displayChar(static_cast<char>(i), false);
    
    displayInt(i, false);
    displayFloat(static_cast<float>(i), false);
    displayDouble(static_cast<double>(i), false);
}

// {...}

void ScalarConverter::convert(const std::string &literal){
    if (literal.empty()){
        std::cout << "Error : empty literal" << std::endl;
        return;
    }

    if (isPseudoLiteral(literal))
        return ;
    
    if (isChar(literal))
    {
        convertFromChar(literal[1]);
        return ;
    }

    if (isInt(literal)){
        errno = 0;
        long tmp = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || tmp < std::numeric_limits<int>::min() || 
            tmp > std::numeric_limits<int>::max()) {
            std::cout << "Error: integer overflow" << std::endl;
            return;
        }
        converFromInt(static_cast<int>(tmp));
        return ;
    }

    std::cout << "Error : Invalid literal format" << std::endl;
}

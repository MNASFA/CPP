#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void) other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void) other;
    return *this;
}
ScalarConverter::~ScalarConverter(){};

// Type detection 
bool ScalarConverter::isChar(const std::string &literal){
    return (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9'));
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
        std::cout << std::fixed << std::setprecision(1) << f;
        std::cout << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::displayDouble(double d, bool impossible){
    std::cout << "double : ";
    if (impossible)
        std::cout << "impossible";
    else{
        std::cout << std::fixed << std::setprecision(1) << d;
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

void ScalarConverter::convertFromInt(int i){
    if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        displayChar(0, true);
    else
        displayChar(static_cast<char>(i), false);

    displayInt(i, false);
    displayFloat(static_cast<float>(i), false);
    displayDouble(static_cast<double>(i), false);
}

void ScalarConverter::convertFromFloat(float f){
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

void ScalarConverter::convertFromDouble(double d){
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

    // Check if double fits in float
    float f_test3 = static_cast<float>(d);
    if ((std::isinf(f_test3) && !std::isinf(d)) || (std::abs(d) > 0 && std::abs(d) > std::numeric_limits<float>::max())) {
        displayFloat(0, true);
    } else {
        displayFloat(f_test3, false);
    }

    displayDouble(d, false);
}

void ScalarConverter::handlePseudoLiteral(const std::string &literal){
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
        if (errno == ERANGE) {
            // Number is too large for long, try double
            errno = 0;
            double d = std::strtod(literal.c_str(), NULL);
            if (errno == ERANGE) {
                std::cout << "Error: number overflow" << std::endl;
                return;
            }
            // Display: char and int impossible, float and double possible
            displayChar(0, true);
            displayInt(0, true);
            float f_test1 = static_cast<float>(d);
            if ((std::isinf(f_test1) && !std::isinf(d)) || (std::abs(d) > 0 && std::abs(d) > std::numeric_limits<float>::max())) {
                displayFloat(0, true);
            } else {
                displayFloat(f_test1, false);
            }
            displayDouble(d, false);
            return;
        }
        if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max()) {
            // Number fits in long but not in int, convert to double
            double d = static_cast<double>(tmp);
            displayChar(0, true);
            displayInt(0, true);
            float f_test2 = static_cast<float>(d);
            if ((std::isinf(f_test2) && !std::isinf(d)) || (std::abs(d) > 0 && std::abs(d) > std::numeric_limits<float>::max())) {
                displayFloat(0, true);
            } else {
                displayFloat(f_test2, false);
            }
            displayDouble(d, false);
            return;
        }
        convertFromInt(static_cast<int>(tmp));
        return ;
    }

    if (isFloat(literal)){
        errno = 0;
        double d = std::strtod(literal.c_str(), NULL);
        if (errno == ERANGE){
            std::cout << "Error : number overflow" << std::endl;
            return ;
        }
        // Check if it fits in float
        float f_test = static_cast<float>(d);
        if ((std::isinf(f_test) && !std::isinf(d)) || (std::abs(d) > 0 && std::abs(d) > std::numeric_limits<float>::max())) {
            // Number doesn't fit in float, but might fit in double
            // Use double for char and int checks
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

            displayFloat(0, true); // impossible for float
            displayDouble(d, false); // but possible for double
        } else {
            convertFromFloat(static_cast<float>(d));
        }
        return ;
    }

    if (isDouble(literal)){
        errno = 0;
        double d = std::strtod(literal.c_str(), NULL);
        if (errno == ERANGE){
            std::cout << "Error : number overflow" << std::endl;
            return ;
        }
        convertFromDouble(d);
        return ;
    }

    std::cout << "Error : Invalid literal format" << std::endl;
}
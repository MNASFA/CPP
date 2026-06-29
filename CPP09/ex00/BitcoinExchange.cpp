#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){(void) other;}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
    (void) other;
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::isValidDate(const std::string &date){
    int m, d;

    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < 10; i++){
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    m = std::atoi(date.substr(5, 2).c_str());
    d = std::atoi(date.substr(8, 2).c_str());

    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false; 
    return true;
};

bool BitcoinExchange::isValidValue(const std::string &value){
    if (value.empty())
        return false;
    
    std::stringstream ss(value);
    float numValue;
    char extra;

    if (!(ss >> numValue) || (ss >> extra))
        return false;

    if (numValue <= 0 || numValue > 1000)
        return false;
    
    return true;
}

void BitcoinExchange::loadData(const std::string &filename){
    std::ifstream file(filename.c_str());

    if (!file.is_open()){
        std::cerr << "Error : could not open file." << std::endl;
        return ;
    }

    std::string line;

    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        std::string date = line.substr(0, commaPos);
        std::string price = line.substr(commaPos + 1);

        if (!isValidDate(date))
            continue;

        std::stringstream ss(price);
        float priceValue;

        if (!(ss >> priceValue))
            continue;

        _db[date] = priceValue;
    }
    file.close();
}

float BitcoinExchange::getPrice(const std::string &date){
    std::map<std::string, float>::iterator it = _db.find(date);

    if (it != _db.end())
        return it->second;
    
    it = _db.lower_bound(date);
    if (it == _db.begin())
        return -1;
    
    --it;
    return it->second;
}

std::string BitcoinExchange::trim(std::string &str){
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::processFile(const std::string &filename){
    std::ifstream file(filename.c_str());

    if(!file.is_open()){
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos){
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string dateStr = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);

        dateStr = trim(dateStr);
        valueStr = trim(valueStr);

        if (!isValidDate(dateStr)){
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue; 
        }

        if (!isValidValue(valueStr)){
            std::stringstream ss(valueStr);

            float numValue;
            if (!(ss >> numValue))
                std::cout << "Errot : bad input => " << line << std::endl;
            else if (numValue < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else if (numValue > 1000)
                std::cout << "Error: too large a number" << std::endl;
            continue;
        }

        float price = getPrice(dateStr);
        if (price == -1){
            std::cout << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        std::stringstream ss(valueStr);
        float value;
        ss >> value;

        float result = value * price;
        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
    file.close();
}
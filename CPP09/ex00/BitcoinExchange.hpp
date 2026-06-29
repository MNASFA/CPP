#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <sstream>
#include <fstream>
#include <algorithm>

class BitcoinExchange {
    private:
        std::map<std::string, float> _db;
        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& value);

        std::string trim(std::string &str);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadData(const std::string& filename);
        void processFile(const std::string& filename);
        float getPrice(const std::string &date);
};

#endif
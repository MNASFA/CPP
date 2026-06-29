#include "BitcoinExchange.hpp"

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    // Check if exactly one argument is provided
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    // Create BitcoinExchange object
    BitcoinExchange btc;
    
    // Load the database
    btc.loadData("data.csv");
    
    // Process the input file
    btc.processFile(argv[1]);
    
    return 0;
}
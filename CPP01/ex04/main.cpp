#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage : ./program <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename =  av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
    {
        std::cerr << "Error : s1 Cannot be empty !" << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error : Cannot Open File : " << filename << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(inputFile, line))
    {
        content += line;
        content += "\n";
    }
    inputFile.close();
    
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error : Cannot Open File : " << outputFilename << std::endl;
        return 1;
    }

    outputFile << content;
    outputFile.close();

    std::cout << "Mission Completed :: Output : " << outputFilename << std::endl;
    return 0;
}
#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac != 2)
    {
        std::cout << "Usage : ./harlFilter <level>" << std::endl;
        return 1;
    }

    std::string level = av[1];
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = 0;
    while (i <= 4)
    {
        if (levels[i] == level)
            break ;
        i++;
    }

    std::cout << std::endl;
    
    switch (i)
    {
        case 0:
            harl.complain("DEBUG");
            /* fall through */
        case 1:
            harl.complain("INFO");
            /* fall through */
        case 2:
            harl.complain("WARNING");
            /* fall through */
        case 3:
            harl.complain("ERROR");
            break;
        default:
            harl.complain("TEST");
    }
}
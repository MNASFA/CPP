#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl{
    private:
        void error(void);
        void debug(void);
        void warning(void);
        void info(void);
    public:
        Harl();
        ~Harl();

        void complain(std::string level);
};

#endif
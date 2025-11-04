#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        
        Fixed(const int nb);
        Fixed(const float f);

        bool operator>(const Fixed &obj);
        bool operator<(const Fixed &obj);
        bool operator>=(const Fixed &obj);
        bool operator<=(const Fixed &obj);
        bool operator==(const Fixed &obj);
        bool operator!=(const Fixed &obj);

        Fixed operator+(const Fixed &);
        Fixed operator-(const Fixed &);
        Fixed operator*(const Fixed &);
        Fixed operator/(const Fixed &);

        static Fixed & const min(Fixed const &a, Fixed const &b);
        static Fixed & min(Fixed &a, Fixed &b);
        static Fixed & const max(Fixed const &a, Fixed const &b);
        static Fixed & max(Fixed &a, Fixed &b);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &cout, Fixed const &obj);

#endif
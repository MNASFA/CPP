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

        Fixed operator+(const Fixed &obj);
        Fixed operator-(const Fixed &obj);
        Fixed operator*(const Fixed &obj);
        Fixed operator/(const Fixed &obj);

        Fixed &operator++(); //(++a)
        Fixed operator++(int); //(a++)
        Fixed &operator--(); //(--a)
        Fixed operator--(int); //(a--)

        static const Fixed &min(Fixed const &a, Fixed const &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &max(Fixed const &a, Fixed const &b);
        static Fixed &max(Fixed &a, Fixed &b);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &cout, Fixed const &obj);

#endif
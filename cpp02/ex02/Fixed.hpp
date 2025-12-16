#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
        private:
                static const int        fractionalBits = 8;
                int     value;
        public:
                Fixed();
                Fixed(const Fixed &other);
                Fixed &operator=(const Fixed &other);
                ~Fixed();
                Fixed(const int integer);
                Fixed(const float floatingPoint);
                int getRawBits( void ) const;
                void setRawBits( int const raw );
                float toFloat( void ) const;
                int toInt( void ) const;
                bool operator>(const Fixed &other) const;
                bool operator>=(const Fixed &other) const;
                bool operator<(const Fixed &other) const;
                bool operator<=(const Fixed &other) const;
                bool operator==(const Fixed &other) const;
                bool operator!=(const Fixed &other) const;
                Fixed operator+(const Fixed &other) const;
                Fixed operator-(const Fixed &other) const;
                Fixed operator*(const Fixed &other) const;
                Fixed operator/(const Fixed &other) const;
                Fixed &operator++(); // pre-increment
                Fixed operator++(int); // post-increment
                Fixed &operator--(); // pre-decrement
                Fixed operator--(int); // post-decrement
                static Fixed &min(Fixed &a, Fixed &b);
                static const Fixed &min(Fixed const &a, Fixed const &b);
                static Fixed &max(Fixed &a, Fixed &b);
                static const Fixed &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream& os, const Fixed& obj);

#endif
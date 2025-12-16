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

};

std::ostream &operator<<(std::ostream& os, const Fixed& obj);

#endif
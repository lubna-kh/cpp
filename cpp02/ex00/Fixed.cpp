# include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
        std::cout<< "Default Constructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value)
{
        std::cout<< "Copy Constructor Called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
        std::cout<< "Copy assignment operator called" << std::endl;
        if (this != &other)
        {
                this->value = other.value;
        }
        return *this;
}

Fixed::~Fixed()
{
        std::cout<< "Destructor Called" << std::endl;
}

int Fixed::getRawBits(void) const
{
        std::cout << "getRawBits member function called" << std::endl;
        return (value);
}

void Fixed::setRawBits(int const raw)
{
        value = raw;
}
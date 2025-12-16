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

Fixed::Fixed (const int integer)
{
	std::cout<< "Int constructor called" << std::endl;
	value = integer<<fractionalBits;
}

Fixed::Fixed (const float floatingPoint)
{
	std::cout << "Float constuctor called"<<std::endl;
	value = static_cast<int>(roundf(floatingPoint * (1 << fractionalBits)));
}

//gives the precise float value with fractional part
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << fractionalBits));//(1 << fractionalBits) it means 2^fractionalBits
}

//gives only the unteger part of the fixed point number
int	Fixed::toInt(void) const
{
	return (value >> fractionalBits);//shift by the number of fractional bits (its like i divid the value by 2^8)
}

std::ostream &operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
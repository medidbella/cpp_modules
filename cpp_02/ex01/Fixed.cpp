#include "Fixed.hpp"

const int Fixed::fractionalBitsNumber = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	value = 0;
}

Fixed::Fixed(const Fixed &dest)
{
	std::cout << "Copy constructor called\n";
	value = dest.value;
}

Fixed::Fixed(const int number)
{
	std::cout << "int constructor called\n";
	value = number << fractionalBitsNumber;
}

Fixed::Fixed(const float number)
{
	std::cout << "float constructor called\n";
	value = 0;
	int integerPart = number;
	float fractionalPart;

	fractionalPart = number - integerPart;
	if (number < 0)
		fractionalPart *= -1;
	value = roundf(fractionalPart * std::pow(2, fractionalBitsNumber));
	value += (integerPart << fractionalBitsNumber);
}

Fixed Fixed::operator =(const Fixed &otherObject)
{
	std::cout << "used copy assignment operator\n";
	value = otherObject.value;
	return *this;
}

void Fixed::setRawBits(int newValue)
{
	std::cout << "setRawBits member function called\n";
	value = newValue;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return value;
}

float Fixed::toFloat() const
{
	int integerPart = value >> fractionalBitsNumber;
	float fractionalPart = 0;
	int divisor = 2;

	for (int bits = fractionalBitsNumber - 1; bits >= 0; bits--)
	{
		fractionalPart += (float)1 / divisor * (value >> bits & 1);
		divisor *= 2;
	}
	return (integerPart + fractionalPart);
}

int Fixed::toInt( void ) const
{
	return (value >> fractionalBitsNumber);
}

std::ostream& operator <<(std::ostream &out, const Fixed &number)
{
	out << number.toFloat();
	return out;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

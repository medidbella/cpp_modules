#include "Fixed.hpp"

bool Fixed::operator <(const Fixed &otherObject)
{
	return (value < otherObject.value);
}

bool Fixed::operator >(const Fixed &otherObject)
{
	return (value > otherObject.value);
}

bool Fixed::operator <=(const Fixed &otherObject)
{
	return (value <= otherObject.value);
}

bool Fixed::operator >=(const Fixed &otherObject)
{
	return (value <= otherObject.value);
}

bool Fixed::operator ==(const Fixed &otherObject)
{
	return (value == otherObject.value);
}

bool Fixed::operator !=(const Fixed &otherObject)
{
	return (value != otherObject.value);
}

Fixed &Fixed::min(Fixed &number1, Fixed &number2)
{
	if (number2.getRawBits() < number1.getRawBits())
		return number2;
	return number1;
}

const Fixed &Fixed::min(const Fixed &number1, const Fixed &number2)
{
	if (number2.getRawBits() < number1.getRawBits())
		return number2;
	return number1;
}

Fixed &Fixed::max(Fixed &number1, Fixed &number2)
{
	if (number2.getRawBits() > number1.getRawBits())
		return number2;
	return number1;
}

const Fixed &Fixed::max(const Fixed &number1, const Fixed &number2)
{
	if (number2.getRawBits() > number1.getRawBits())
		return number2;
	return number1;
}
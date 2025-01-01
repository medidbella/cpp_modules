#include "Fixed.hpp"

Fixed Fixed::operator =(const Fixed &otherObject)
{
	std::cout << "used copy assignment operator\n";
	value = otherObject.value;
	return *this;
}

Fixed Fixed::operator +(const Fixed &otherObject)
{
	Fixed res(this->toFloat() + otherObject.toFloat());
	return res;
}

Fixed Fixed::operator -(const Fixed &otherObject)
{
	Fixed res(this->toFloat() - otherObject.toFloat());
	return res;
}

Fixed Fixed::operator *(const Fixed &otherObject)
{
	Fixed res(this->toFloat() * otherObject.toFloat());
	return res;
}

Fixed Fixed::operator /(const Fixed &otherObject)
{
	Fixed res(this->toFloat() / otherObject.toFloat());
	return res;
}

Fixed Fixed::operator ++(void)
{
	this->value += 1;
	Fixed res(*this);
	return res;
}

Fixed Fixed::operator ++(int)
{
	Fixed res(*this);
	this->value += 1;
	return res;
}

Fixed Fixed::operator --(void)
{
	this->value -= 1;
	Fixed res(*this);
	return res;
}

Fixed Fixed::operator --(int)
{
	Fixed res(*this);
	this->value -= 1;
	return res;
}

#include "Fixed.hpp"

const int Fixed::fractionalBitsNumber = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called\n";
	value = 0;
}

Fixed::Fixed(const Fixed &dest){
	std::cout << "Copy constructor called\n";
	value = dest.value;
}

void Fixed::operator=(const Fixed &otherObject){
	std::cout << "used copy assignment operator\n";
	value = otherObject.value;
}

void Fixed::setRawBits(int newValue){
	std::cout << "setRawBits member function called\n";
	value = newValue;
}

int Fixed::getRawBits(){
	std::cout << "getRawBits member function called\n";
	return value;
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}
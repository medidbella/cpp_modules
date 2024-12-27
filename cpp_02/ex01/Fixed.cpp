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

Fixed::Fixed(const int number){
	value = number << fractionalBitsNumber;
}

// Fixed::Fixed(const float number){
// 	int bits_iter;
// 	char *ptr = (char *)&this->value;

// 	if ((number > 0 && number < 1) || (number < 0 && number > -1))
// 		*(ptr + 2) = 0;
// 	else
// 		*(ptr + 2) = roundf(number);
// 	//fractional part
	
// }

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
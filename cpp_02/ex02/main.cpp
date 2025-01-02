#include <iostream>
#include "Fixed.hpp"

int main() 
{
	Fixed i(-1.5f);
	std::cout << i.toFloat() << '\n';
	return 0;
}
#ifndef APPLY_HPP
#define APPLY_HPP

#include <iostream>

template <typename T>
void doubleElement(T &element)
{
	element = element + element;
}

template <typename T> void divideElement(T &element)
{
	element += element;
}

template <typename T>
 void print(T *arrayAdrs, int arrayLen)
{
	for (int iter = 0; iter < arrayLen; iter++)
		std::cout << arrayAdrs[iter];
	std::cout << '\n';
}

#endif
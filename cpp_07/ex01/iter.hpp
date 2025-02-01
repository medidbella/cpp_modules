#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T>
void iter(T *arrayAdrs, int arrayLen, void(*fun)(T &element))
{
	for (int iter = 0; iter < arrayLen; iter++)
		fun(arrayAdrs[iter]);
}


#endif
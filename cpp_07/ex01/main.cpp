#include "iter.hpp"
#include "utils.hpp"
#include "Block.hpp"
#include <iostream>

void arrayInit(t_Block *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i].member1 = i + 1;
		array[i].member2 = i + 1;
		array[i].member3 = i + 1;
	}
}

int main()
{
	//array of integers
	{
		const int size = 5;
		int array[size] = {1, 2, 3, 4, 5};
		std::cout << "int array before : ";
		print(array, 5);
		iter(array, 5, doubleElement);
		std::cout << "int array after  : ";
		print(array, 5);
		std::cout << '\n';
	}
	//array of doubles
	{
		const int size = 5;
		double array[size] = {1, 2, 3, 4, 5};
		std::cout << "double array before : ";
		print(array, 5);
		iter(array, 5, divideElement);
		std::cout << "double array after  : ";
		print(array, 5);
		std::cout << '\n';
	}
	//array of structs
	{
		const int size = 5;
		t_Block array[size];
		arrayInit(array, size);
		std::cout << "struct array before :\n";
		print(array, 5);
		iter(array, 5, doubleElement);
		std::cout << "after :\n";
		print(array, 5);
	}
}

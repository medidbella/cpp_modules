#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include "Block.hpp"
#define MAX_VAL 750

int main(int, char**)
{
    Array<t_Block> myArray(5);
	myArray[4] = t_Block(1, 2, 3);
	myArray[0] = t_Block(44, 44, 42);
	for (int i = 0; (unsigned)i < myArray.size(); i++)
		std::cout << myArray[i] << '\n';
	try
	{
		std::cout << myArray[5] << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "caught an exception\n";
		std::cerr << e.what() << '\n';
	}
}
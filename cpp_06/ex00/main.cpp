#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int Argc, char **Argv)
{
	if (Argc != 2)
	{	
		std::cerr << "usage: ./convert <one-argument>\n";
		return 1;
	}
	std::string input(Argv[1]);
	if (input.empty())
	{
		std::cerr << "error: empty string\n";
		return 1;
	}
	ScalarConverter::convert(input);
}

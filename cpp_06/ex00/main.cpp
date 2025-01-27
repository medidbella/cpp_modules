#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0

// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan

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

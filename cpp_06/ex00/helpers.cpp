#include "helpers.hpp"

bool	isNumeric(std::string &input)
{
	int i = 0;
	while (std::isspace(input[i]))
		i++;
	while (i < input.length())
		if (!std::isdigit(input[i++]))
			return false;
	return true;
}

bool isChar(std::string &input)
{
	int i = 0;
	while (std::isspace(input[i]))
		i++;
	if (std::isdigit(input[i]))
		return false;
	while (i < input.length())
		i++;
	return true;
}

void getCorrectType(std::string &input, void *type)
{


	if (isChar(input))
		type = new char(input[0]);
	
}
#include "ScalarConverter.hpp"

void explicitCasting(char value)
{
	std::cout << "char: '" << value << "'\n";
	std::cout << "int: " << (int)value << '\n';
	std::cout << "float: " << (float)value << '\n';
	std::cout << "double: " << (double)value << '\n';
}

void explicitCasting(float value)
{
	if (value == nanf("") || value == std::numeric_limits<float>::infinity()
		|| value == -std::numeric_limits<float>::infinity())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else 
	{
		if (!std::isprint((int)value))
			std::cout << "char: 'impossible'\n";
		else
			std::cout << "char: '" << (char)value << "'\n";
		std::cout << "int: " << value << '\n';
	}
	std::cout << "float: " << (float)value << '\n';
	std::cout << "double: " << (double)value << '\n';
}

void explicitCasting(double value)
{
	if (value == nan("") || value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else 
	{
		if (!std::isprint((int)value))
			std::cout << "char: 'impossible'\n";
		else
			std::cout << "char: '" << (char)value << "'\n";
		std::cout << "int: " << value << '\n';
	}
	std::cout << "float: " << (float)value << '\n';
	std::cout << "double: " << (double)value << '\n';
}

void explicitCasting(int value)
{
	if (std::isprint(value))
		std::cout << "char: '" << (char)value << "'\n";
	else 
		std::cout << "char: 'inprintable'\n";
	std::cout << "int: " << value << '\n';
	std::cout << "float: " << (float)value << '\n';
	std::cout << "double: " << (double)value << '\n';
}

void ScalarConverter::convert(const std::string &scalar)
{
	int dataType = -1;
	void *valuePtr = NULL;
	getCorrectType(scalar, &valuePtr, &dataType);
	if (!valuePtr)
	{
		std::cerr << "some error occurred\n";
		return;
	}

	switch (dataType)
	{
		case CHAR_FORM:
			std::cout << "type = char\n" << *(char *)valuePtr << '\n';
			explicitCasting(*(char*)valuePtr);
			delete (char*)valuePtr;
			break;
		case INT_FORM:
			std::cout << "type = int\n" << *(int *)valuePtr << '\n';
			explicitCasting(*(int*)valuePtr);
			delete (int*)valuePtr;
			break;
		case FLOAT_FORM:
			std::cout << "type = float\n" << *(float *)valuePtr << '\n';
			explicitCasting(*(float*)valuePtr);
			delete (float*)valuePtr;
			break;
		case DOUBLE_FORM:
			std::cout << "type = double\n" << *(double *)valuePtr << '\n';
			explicitCasting(*(double*)valuePtr);
			delete (double*)valuePtr;
			break;
		default:
			std::cerr << "overflow\n";
	}
}

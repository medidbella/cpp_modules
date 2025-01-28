#include "ScalarConverter.hpp"

void explicitCasting(char value)
{
	std::cout << "char: '" << value << "'\n";
	std::cout << "int: " << static_cast<int>(value)<< '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value)<< '\n';
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value)<< '\n';
}

void explicitCasting(float value)
{
	if (isnanf(value) || value == std::numeric_limits<float>::infinity()
		|| value == -std::numeric_limits<float>::infinity())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else 
	{
		if (isascii(value) && std::isprint(value))
			std::cout << "char: '" << static_cast<char>(value)<< "'\n";
		else
			std::cout << "char: impossible\n";
		std::cout << "int: " << static_cast<int>(value)<< '\n';
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value)<< 'f' << '\n';
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value)<< '\n';
}

void explicitCasting(double value)
{
	if (std::isnan(value) || value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else 
	{
		if (isascii(value) && std::isprint(value))
			std::cout << "char: '" << static_cast<char>(value)<< "'\n";
		else
			std::cout << "char: impossible\n";
		std::cout << "int: " << static_cast<int>(value)<< '\n';
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) <<  static_cast<float>(value)<< 'f' << '\n';
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value)<< '\n';
}

void explicitCasting(int value)
{
	if (isascii(value) && std::isprint(value))
		std::cout << "char: '" << static_cast<char>(value)<< "'\n";
	else 
		std::cout << "char: impossible\n";
	std::cout << "int: " << value << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value)<< 'f' << '\n';
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value)<< '\n';
}

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &source){
	(void)source;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source){
	(void)source;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string &scalar)
{
	int dataType = -1;
	void *valuePtr = NULL;
	getCorrectType(scalar, &valuePtr, &dataType);
	if (!valuePtr)
		return ;
	switch (dataType)
	{
		case CHAR_FORM:
			explicitCasting(*static_cast<char*>(valuePtr));
			delete (char*)valuePtr;
			break;
		case INT_FORM:
			explicitCasting(*static_cast<int*>(valuePtr));
			delete (int*)valuePtr;
			break;
		case FLOAT_FORM:
			explicitCasting(*static_cast<float*>(valuePtr));
			delete (float*)valuePtr;
			break;
		case DOUBLE_FORM:
			explicitCasting(*static_cast<double*>(valuePtr));
			delete (double*)valuePtr;
			break;
	}
}

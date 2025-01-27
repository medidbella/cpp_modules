#include "helpers.hpp"

void toInteger(std::string &input, void **value)
{
	double result;
	result = std::strtol(input.c_str(), NULL, 10);
	if (errno == ERANGE || result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
	{
		value = NULL;
		std::cerr << "integer overflow\n";
		return ;
	}
	*value = new int((int)result);
	return ;
}

bool checkForPseudoLiterals(std::string &input, void **value)
{
	std::string pseudo_literals[6] = {"nanf", "+inff", "-inff", "nan", "+inf", "-inf"};
	int i;
	for (i = 0; i < 6 ;i++)
	{
		if (pseudo_literals[i] == input)
			break;
	}
	switch (i)
	{
		case 0:
			*value = new float(nanf(""));
			break;
		case 1:
			*value = new float(std::numeric_limits<float>::infinity());
			break;
		case 2:
			*value = new float(-std::numeric_limits<float>::infinity());
			break;
		case 3:
			*value = new double(nan(""));
			break;
		case 4:
			*value = new double(std::numeric_limits<double>::infinity());
			break;
		case 5:
			*value = new double(-std::numeric_limits<double>::infinity());
			break;
	}
	if (i < 6)
		return true;
	return false;
}

void toFloat(std::string &input, void **value)
{
	float res = 0;
	if (checkForPseudoLiterals(input, value))
		return ;
	std::stringstream floatString(input);
	floatString >> res;
	if (floatString.fail() || std::isinf(res) || std::isnan(res))
	{
		value = NULL;
		std::cerr << "float overflow\n";
		return ; 
	}
	*value = new float(res);
	return;
}

void toDouble(std::string &input, void **value)
{
	double res = 0;
	if (checkForPseudoLiterals(input, value))
		return ;
	std::stringstream doubleString(input);
	if (doubleString.fail() || std::isinf(res) || std::isnan(res))
	{
		value = NULL;
		std::cerr << "double overflow\n";
		return ;
	}
	doubleString >> res;
	*value = new double(res);
	return;
}

std::string	trimString(const std::string &input)
{
	size_t	start = input.find_first_not_of(" \t\n\v\f\r");
	size_t	end = input.find_last_not_of(" \t\n\v\f\r");

	if (end > input.length() || start > input.length())
		return "";
	return input.substr(start, end - start + 1);
}

int	checkFormat(std::string &input)
{
	bool decimalPoint = false;
	size_t i = 1;

	if (input == "nanf" || input == "+inff" || input == "-inff")
		return FLOAT_FORM;
	else if (input == "nan" || input == "+inf" || input == "-inf")
		return DOUBLE_FORM;
	if (input[0] != '+' && input[0] != '-' && !std::isdigit(input[0]))
		return INDEFINED_FORM;
	while (i < input.length())
	{
		if (input[i] == '.' && decimalPoint == true)
			return INDEFINED_FORM;
		else if (input[i] == '.' && std::isdigit(input[i + 1]))
			decimalPoint = true;
		else if (input[i] == 'f' && i == input.length() - 1 && decimalPoint)
			return FLOAT_FORM;
		else if (!std::isdigit(input[i]))
			return INDEFINED_FORM;
		i++;
	}
	if (decimalPoint)
		return DOUBLE_FORM;
	return
		INT_FORM;
}

void getCorrectType(const std::string &input, void **value, int *type)
{
	int format;
	std::string trimmed;
	trimmed = trimString(input);
	if (input.empty())
	{
		std::cerr << "empty string after trimming\n";
		value = NULL;
	}
	if (trimmed.length() == 1 && !std::isdigit(input[0]))
	{
		*value = new char(input[0]);
		*type = CHAR_FORM ;
		return ;
	}
	format = checkFormat(trimmed);
	*type = format;
	switch (format)
	{
		case INT_FORM:
			return toInteger(trimmed, value);
		case FLOAT_FORM:
			return toFloat(trimmed, value);
		case DOUBLE_FORM:
			return toDouble(trimmed, value);
		default:
			std::cerr << "syntax error\n";
			value = NULL;
	}
	return ;
}
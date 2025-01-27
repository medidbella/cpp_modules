#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include "helpers.hpp"
#include <iostream>
#include <string>
#include <climits>

class ScalarConverter
{
	public:
		static void convert(const std::string &scalar);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &source);
		ScalarConverter &operator=(const ScalarConverter &source);
		~ScalarConverter();
};

#endif

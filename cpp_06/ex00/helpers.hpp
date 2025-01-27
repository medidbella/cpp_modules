#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <cerrno>

#define CHAR_FORM 0
#define INT_FORM 1
#define FLOAT_FORM 2
#define DOUBLE_FORM 3
#define INDEFINED_FORM 4

void getCorrectType(const std::string &input, void **value, int *type);

#endif	
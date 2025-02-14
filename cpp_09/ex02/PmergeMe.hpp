#ifndef PMERGEME
#define PMERGEME

#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <exception>

class BadInputException : public std::exception
{
	public:
		BadInputException();
		const char *what() const throw();
		~BadInputException() throw();
};

void inputParser(std::vector<int> &lst, std::string input);
void mergerInsertionSort(std::vector<int> &input);
#endif
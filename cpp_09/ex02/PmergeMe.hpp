#ifndef PMERGEME
#define PMERGEME

#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <exception>
#include <sys/time.h> 

class BadInputException : public std::exception
{
	public:
		BadInputException();
		const char *what() const throw();
		~BadInputException() throw();
};


std::size_t getCurrentTime();
void 		inputParser(std::vector<int> &lst, char **input);
void 		mergerInsertionSort(std::vector<int> &input);
#endif
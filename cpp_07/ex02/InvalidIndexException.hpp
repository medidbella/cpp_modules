#ifndef INVALID_INDEX_EXCEPTION
#define INVALID_INDEX_EXCEPTION

#include <exception>
#include <iostream>

class InvalidIndexException : public std::exception
{
	private:
		std::string errorMessage;
	public:
		InvalidIndexException();
		const char* what() const throw();
		~InvalidIndexException() throw();
};

#endif
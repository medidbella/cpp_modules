#ifndef UNSIGNED_FORM_EXCEPTION_HPP
#define UNSIGNED_FORM_EXCEPTION_HPP

#include <exception>
#include <iostream>

class UnsignedFormException : public std::exception
{
	private:
		std::string errorMessage;
	public:
		UnsignedFormException();
		const char* what() const throw();
		~UnsignedFormException() throw();
};

#endif
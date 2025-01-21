#ifndef LOW_GRADE_EXCEPTION_HPP
#define LOW_GRADE_EXCEPTION_HPP

#include <exception>
#include <iostream>

class GradeTooLowException : public std::exception
{
	private:
		std::string	errorMessage;
	public:
		GradeTooLowException();
		const char* what() const throw();
		~GradeTooLowException() throw();
};

#endif
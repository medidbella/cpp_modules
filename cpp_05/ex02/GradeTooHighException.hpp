#ifndef HIGH_GRADE_EXCEPTION_HPP
#define HIGH_GRADE_EXCEPTION_HPP

#include <exception>
#include <iostream>

class GradeTooHighException : public std::exception
{
	private:
		std::string errorMessage;
	public:
		GradeTooHighException();
		const char* what() const throw();
		~GradeTooHighException() throw();
};

#endif
#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException()
{
	errorMessage = "the provided grade is too high, the grade range is (1-150)";
}

const char *GradeTooHighException::what() const throw(){
	return (char *)errorMessage.c_str();
}

GradeTooHighException::~GradeTooHighException() throw()
{
	
}
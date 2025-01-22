#include "ExcuteUnsigedFormException.hpp"

#include "GradeTooHighException.hpp"

UnsignedFormException::UnsignedFormException()
{
	errorMessage = "the provide Form is unsigned";
}

const char *UnsignedFormException::what() const throw(){
	return (char *)errorMessage.c_str();
}

UnsignedFormException::~UnsignedFormException() throw()
{
	
}
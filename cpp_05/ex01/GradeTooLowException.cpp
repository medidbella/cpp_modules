#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException()
{
	errorMessage = "the provided grade is too Low";
}

const char *GradeTooLowException::what() const throw(){
	return (char *)errorMessage.c_str();
}

GradeTooLowException::~GradeTooLowException() throw(){

}
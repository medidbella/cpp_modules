#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException()
{
	errorMessage = "the provided grade is too Low, the grade range is (1-150)";
}

const char *GradeTooLowException::what() const throw(){
	return (char *)errorMessage.c_str();
}

GradeTooLowException::~GradeTooLowException() throw(){

}
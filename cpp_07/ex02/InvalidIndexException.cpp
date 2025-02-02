#include "InvalidIndexException.hpp"

InvalidIndexException::InvalidIndexException()
{
	errorMessage = "index outside array bonds";
}

const char *InvalidIndexException::what() const throw(){
	return (char *)errorMessage.c_str();
}

InvalidIndexException::~InvalidIndexException() throw(){

}

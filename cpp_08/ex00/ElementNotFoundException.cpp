#include "ElementNotFoundException.hpp"

ElementNotFoundException::ElementNotFoundException()
{
	message = "element not found in the container";
}

const char *ElementNotFoundException::what() const throw(){
	return message.c_str();
}

ElementNotFoundException::~ElementNotFoundException() throw(){

}

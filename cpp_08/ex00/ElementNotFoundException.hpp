#ifndef ELEMENT_NOT_FOUND_HPP
#define ELEMENT_NOT_FOUND_HPP

#include <exception>
#include <string>

class ElementNotFoundException : public std::exception
{
	private:
		std::string	message;
	public:
		ElementNotFoundException();
		const char *what() const throw();
		~ElementNotFoundException() throw();
};

#endif
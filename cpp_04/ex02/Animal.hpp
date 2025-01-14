#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &src);
		virtual ~Animal();
		std::string	getType() const;
		void setType(std::string &newType);
		Animal& operator=(const Animal &src);
		virtual void makeSound() const = 0;
};
#endif
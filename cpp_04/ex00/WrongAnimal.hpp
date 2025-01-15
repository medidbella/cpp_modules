#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal();
		std::string	getType() const;
		void setType(std::string &newType);
		WrongAnimal& operator=(const WrongAnimal &src);
		void makeSound() const;
};
#endif
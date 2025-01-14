#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain *dogBrain;
	public:
		Dog();
		Dog(const Dog& src);
		void makeSound() const;
		~Dog();
};

#endif
#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& src);
		~Cat();
};


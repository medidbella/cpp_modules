#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
	private:
		Brain *catBrain;
	public:
		Cat();
		Cat(const Cat& src);
		void makeSound() const;
		Cat &operator=(const Cat& src);
		virtual ~Cat();
};

#endif
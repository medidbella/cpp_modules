#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& src);
		void makeSound() const;
		~WrongCat();
};

#endif
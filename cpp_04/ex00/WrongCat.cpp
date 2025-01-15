#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "WrongCat default constructor used\n";
	type = "Cat";
}

WrongCat::WrongCat(const WrongCat& src){
	std::cout << "WrongCat copy constructor used\n";
	type = src.type;
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat is making a sound : mew mew ...\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor used\n";
}

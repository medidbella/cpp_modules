#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor used\n";
	type = "Cat";
}

Cat::Cat(const Cat& src){
	std::cout << "Cat copy constructor used\n";
	type = src.type;
}

void Cat::makeSound() const{
	std::cout << "Cat is making a sound : mew mew ...\n";
}

Cat::~Cat()
{
	std::cout << "cat destructor used\n";
}

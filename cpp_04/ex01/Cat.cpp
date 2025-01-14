#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor used\n";
	type = "Cat";
	catBrain = new Brain();
}

Cat::Cat(const Cat& src){
	std::cout << "Cat copy constructor used\n";
	catBrain = new Brain();
	*catBrain = *src.catBrain;
	type = src.type;
}

void Cat::makeSound() const{
	std::cout << "Cat is making a sound : mew mew ...\n";
}

Cat &Cat::operator=(const Cat &src)
{
	type = src.type;
	*catBrain = *src.catBrain;
	return *this;
}

Cat::~Cat()
{
	std::cout << "cat destructor used\n";
	delete catBrain;
}

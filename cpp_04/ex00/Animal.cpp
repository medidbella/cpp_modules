#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor used\n";
	type = "undefined";
}

Animal::Animal(const Animal &src){
	std::cout << "animal copy constructor is used";
	type = src.type;
}

void Animal::makeSound(){
	if (type == "Cat")
		std::cout << "Cat is making a sound : mew mew ...\n";
	else if (type == "Dog")
		std::cout << "Dog is making a sound : ouf ouf ...\n";
	else
		std::cout << "Animal is making an unknown sound : non\n";
}

Animal &Animal::operator=(const Animal &src){
	type = src.type;
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor is called\n";
}
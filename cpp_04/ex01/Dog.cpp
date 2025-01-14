#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog default constructor used\n";
	type = "Dog";
	dogBrain = new Brain();
}

Dog::Dog(const Dog& src){
	std::cout << "Dog copy constructor used\n";
	dogBrain = new Brain();
	*dogBrain = *src.dogBrain;
	type = src.type;
}

void Dog::makeSound() const{
	std::cout << "Dog is making a sound : bark bark ...\n";
}

Dog &Dog::operator=(const Dog &src)
{
	type = src.type;
	*dogBrain = *src.dogBrain;
	return *this; 
}

Dog::~Dog()
{
	std::cout << "Dog destructor used\n";
	delete dogBrain;
}

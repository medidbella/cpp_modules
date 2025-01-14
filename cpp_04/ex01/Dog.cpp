#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog default constructor used\n";
	type = "Dog";
	dogBrain = new Brain();
}

Dog::Dog(const Dog& src){
	std::cout << "Dog copy constructor used\n";
	type = src.type;
}
void Dog::makeSound() const{
	std::cout << "Dog is making a sound : bark bark ...\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor used\n";
	delete dogBrain;
}

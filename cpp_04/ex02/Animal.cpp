#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor used\n";
	type = "undefined";
}

Animal::Animal(const Animal &src){
	std::cout << "animal copy constructor is used\n";
	type = src.type;
}

Animal &Animal::operator=(const Animal &src){
	type = src.type;
	return *this;
}

void Animal::setType(std::string &newType){
	type = newType;
}

std::string Animal::getType(void) const{
		return type;
}

Animal::~Animal(){
	std::cout << "Animal destructor is used\n";
}
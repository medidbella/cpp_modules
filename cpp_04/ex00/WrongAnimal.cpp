#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal default constructor used\n";
	type = "undefined";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	std::cout << "WrongAnimal copy constructor is used\n";
	type = src.type;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal is making an unknown sound : non\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src){
	type = src.type;
	return *this;
}

void WrongAnimal::setType(std::string &newType){
	type = newType;
}

std::string WrongAnimal::getType(void) const{
		return type;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor is used\n";
}
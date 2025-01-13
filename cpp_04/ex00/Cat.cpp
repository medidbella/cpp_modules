#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor used\n";
	type = "Cat";
}

Cat::Cat(const Cat& src){
	std::cout << "Cat copy constructor used"
}
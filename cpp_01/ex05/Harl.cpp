#include "Harl.hpp"

void Harl::debug(void){
	std::cout << "I love some extra bacon for my burger.\n";
}

void Harl::info(void){
	std::cout << "adding extra bacon costs more money!!\n";
}

void Harl::warning(void){
	std::cout << "I deserve to have some extra bacon for free.\n";
}

void Harl::error(void){
	std::cout << "I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
}

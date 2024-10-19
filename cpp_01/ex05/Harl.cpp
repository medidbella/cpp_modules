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


Harl::Harl(void)
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] =  "ERROR";

	ft_ptrs[0] = &Harl::debug;
    ft_ptrs[1] = &Harl::info;
    ft_ptrs[2] = &Harl::warning;
    ft_ptrs[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			(this->*ft_ptrs[i])();
}

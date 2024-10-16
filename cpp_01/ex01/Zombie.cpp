#include "Zombie.hpp"

void Zombie::announce(void){
	std::cout << name + ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string zombie_name){
	name = zombie_name;
}

Zombie::~Zombie(void){
	std::cout << name + " died\n";
}
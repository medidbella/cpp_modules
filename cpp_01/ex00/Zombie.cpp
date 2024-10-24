#include "Zombie.hpp"

Zombie::Zombie(std::string zombie_name){
	name = zombie_name;
}

void Zombie::announce(void){
	std::cout << name + ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(void){
	std::cout << name + " died\n";
}
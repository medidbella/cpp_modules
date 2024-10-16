#include "HumanB.hpp"

void HumanB::attack(void){
	std::cout <<  name + "tacks with their" + used_weapon.getType() + '\n';
}

HumanB::HumanB(std::string new_name){
	name = new_name;
}

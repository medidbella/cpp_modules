#include "HumanB.hpp"

void HumanB::attack(void){
	std::cout <<  name + " atacks with their " + used_weapon->getType() + '\n';
}

HumanB::HumanB(std::string new_name){
	name = new_name;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	used_weapon = &new_weapon;
}


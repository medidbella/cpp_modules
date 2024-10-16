#include "HumanA.hpp"

void HumanA::attack(void){
	std::cout <<  name + " atacks with their " + used_weapon.getType() + '\n';
}

HumanA::HumanA(std::string new_name, Weapon new_weapon){
	used_weapon = new_weapon;
	name = new_name;
}

void HumanA::setWeapon(std::string new_weapon)
{

}
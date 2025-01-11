#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	setName("unnamed");
	setAttackDamage(20);
	setEnergyPoints(50);
	setHitPoints(100);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called\n";
	setName(name);
	setAttackDamage(20);
	setEnergyPoints(50);
	setHitPoints(100);
}
ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " + getName() + " destructor called\n";
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " + getName() + " is now in Gatekeeper mode\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (getEnergypoints() <= 0){
		std::cout << "ScavTrap " + getName() + " can't attack (insefisent energy points)\n";
		return ;
	}
	else if (getHitPoints() <= 0){
		std::cout << "ScavTrap " + getName() + " can't attack (insefisent hit points)\n";
		return;
	}
	setEnergyPoints(getEnergypoints() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!\n";
}
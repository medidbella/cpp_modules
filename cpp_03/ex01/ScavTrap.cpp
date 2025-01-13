#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	name = "unnamed";
	attackDamage = 20;
	energyPoints = 50;
	hitPoints = 100;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called\n";
	this->name = name;
	attackDamage = 20;
	energyPoints = 50;
	hitPoints = 100;
}
ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " + name + " destructor called\n";
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " + name + " is now in Gatekeeper mode\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints <= 0){
		std::cout << "ScavTrap " + name + " can't attack (insefisent energy points)\n";
		return ;
	}
	else if (hitPoints <= 0){
		std::cout << "ScavTrap " + name + " can't attack (insefisent hit points)\n";
		return;
	}
	energyPoints -= 1;
	std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!\n";
}

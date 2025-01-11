#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called\n";
	setName("unnamed");
	setHitPoints(100);
	setAttackDamage(30);
	setEnergyPoints(100);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap default constructor called\n";
	setName(name);
	setHitPoints(100);
	setAttackDamage(30);
	setEnergyPoints(100);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " + getName() + " destructor called\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap "+ getName() +" is requesting a high five\n";
}

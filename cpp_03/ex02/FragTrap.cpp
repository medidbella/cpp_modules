#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called\n";
	name = "unnamed";
	hitPoints = 100;
	attackDamage = 30;
	energyPoints = 100;
}

FragTrap::FragTrap(std::string newName)
{
	std::cout << "FragTrap default constructor called\n";
	name = newName;
	hitPoints = 100;
	attackDamage = 30;
	energyPoints = 100;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " + name + " destructor called\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap "+ name +" is requesting a high five\n";
}

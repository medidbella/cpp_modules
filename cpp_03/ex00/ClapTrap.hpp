#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <iostream>

class ClapTrap{
	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		int AttackDamage;
	
	public:
		ClapTrap();
		ClapTrap& operator=(const ClapTrap &source);
		ClapTrap(const ClapTrap &source);
		ClapTrap(std::string initName);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int getHitPoints();
		int getEnergypoints();
		int getAttackDamage();
		void setName(std::string newName);
		void setAttackDamage(int newValue);
		void setEnergyPoints(int newValue);
		void setHitPoints(int newValue);
		std::string getName();
		~ClapTrap();
};

#endif
#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{

	public:
		ScavTrap();
		ScavTrap(std::string initName);
		void attack(const std::string& target);
		void guardGate();
		~ScavTrap();
};

#endif

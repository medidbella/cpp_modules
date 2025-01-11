#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		void highFivesGuys(void);
};
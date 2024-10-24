#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *res = new (std::nothrow) Zombie(name);
	return (res);
}

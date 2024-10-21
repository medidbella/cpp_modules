#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *res = new (std::nothrow) Zombie;
	res->set_name(name);
	return (res);
}

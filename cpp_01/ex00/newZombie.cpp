#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	try {
		Zombie *res = new Zombie;
		res->set_name(name);
		return (res);
	}
	catch (const std::bad_alloc& e){
		return NULL;
	}
}

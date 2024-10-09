#include <Zombie.hpp> 

Zombie* newZombie(std::string name)
{
	try {
		Zombie *res = new Zombie;
		return (res);
	}
	catch (const std::bad_alloc& e){
		return NULL;
	}
}

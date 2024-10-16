#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie brain_eater;
    brain_eater.set_name(name);
    brain_eater.announce();
}

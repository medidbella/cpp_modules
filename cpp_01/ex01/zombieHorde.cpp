#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    try{
        Zombie* zombies = new Zombie[N];

        for (int iter = 0; iter < N; iter++)
            zombies[iter].set_name(name);
        return (zombies);
    }
    catch(const std::bad_alloc& e){
        return NULL;
    }
}

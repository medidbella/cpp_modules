#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* zombies = new (std::nothrow) Zombie[N];
    if (!zombies)
        return (NULL);
    for (int iter = 0; iter < N; iter++)
            zombies[iter].set_name(name);
        return (zombies);
}

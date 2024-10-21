#include "Zombie.hpp"

int main()
{
    Zombie *ptr = newZombie("heap zombie");
    if (!ptr)
        return (1);
    ptr->announce();
    randomChump("stack zombie");
    delete ptr;
}

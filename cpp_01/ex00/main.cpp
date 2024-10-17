#include "Zombie.hpp"

int main()
{
    Zombie *ptr = newZombie("heap zombie");
    if (!ptr)
        return (1);
    randomChump("stack zombie");
    ptr->announce();
    delete ptr;
}
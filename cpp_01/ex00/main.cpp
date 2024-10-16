#include "Zombie.hpp"

int main()
{
    Zombie *ptr = newZombie("heap zombie");
    randomChump("stack zombie");
    ptr->announce();
    delete ptr;
}
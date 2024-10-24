#include "Zombie.hpp"

int main()
{
    int size = 13;
    Zombie *hord = zombieHorde(13, "hord_member");
    if (!hord)
        return (1);
    for (int iter = 0; iter < size; iter++)
        hord[iter].announce();
    delete[] hord;
}
#include "Zombie.hpp"

int main()
{
    int size = 4;
    Zombie *hord = zombieHorde(size, "hord_member");
    for (int iter = 0; iter < size; iter++)
        hord[iter].announce();
    delete[] hord;
}
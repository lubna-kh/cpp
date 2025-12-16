#include "Zombie.hpp"

int main()
{
    int n = 4;
    Zombie *zombie = zombieHorde(n, "lubna");

    for (int i = 0;i < n;i++)
    {
        zombie[i].announce();

    }

    delete[] zombie;
    return 0;
}
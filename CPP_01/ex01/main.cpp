#include "Zombie.hpp"

int main()
{
    int N = 5;

    Zombie** horde = zombieHorde(N, "Bob");

    int i = 0;
    while (i < N)
    {
        horde[i]->announce();
        i++;
    }
    i = 0;
    while (i < N)
    {
        delete horde[i];
        i++;
    }
    delete[] horde;
    return 0;
}

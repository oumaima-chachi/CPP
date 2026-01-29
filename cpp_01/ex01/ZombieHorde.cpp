#include "Zombie.hpp"

Zombie** zombieHorde(int N, std::string name)
{
    int i;

    i = 0;
    if (N <= 0)
        return NULL;
    Zombie** hrd = new Zombie*[N];
    while (i < N)
    {
        hrd[i]= new Zombie(name);
        i++;
    }
    return hrd;
}

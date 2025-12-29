#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    n_Zombie = name;
}

void Zombie::announce()
{
    std::cout << n_Zombie << ": BraiiiiiiinnnzzzZ..." << "\n";
}

Zombie::~Zombie()
{
    std::cout << n_Zombie << " is destroyed" << "\n";
}

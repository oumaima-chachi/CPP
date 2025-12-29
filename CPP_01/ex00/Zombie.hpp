#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string n_Zombie;
    
    public:
        Zombie(std::string name);
        void announce();
        ~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif 

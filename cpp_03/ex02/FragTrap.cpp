#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " is born!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " is destroyed!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "FragTrap " << name << " cannot attack!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!"
              << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}

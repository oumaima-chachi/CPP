#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructed. " << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed. " << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or any hit points left to attack :( " << std::endl;
    }
    else
    {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else
        hitPoints -= amount;

    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount)
{   
    if (energyPoints <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or any hit points left to repair :( " << std::endl;
    }
    else
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " repairs " << amount << " hit points" << std::endl;
    }
}


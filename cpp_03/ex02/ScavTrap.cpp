#include "ScavTrap.hpp"
#include "iostream"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructed" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name
              << " is now in Gate keeper mode!" << std::endl;
}

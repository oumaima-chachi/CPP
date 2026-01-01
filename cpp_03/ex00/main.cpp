#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap robot("CL4P-TP");//constructor lifih name cree un objet robot 

    robot.attack("Target1");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10);
    robot.attack("Target2");
    robot.beRepaired(5);

    return 0;
}
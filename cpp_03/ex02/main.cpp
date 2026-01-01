#include "FragTrap.hpp"

int main()
{
    FragTrap robot("Bob");

    robot.attack("Enemy1");
    robot.takeDamage(40);
    robot.beRepaired(30);
    robot.highFivesGuys();

    return 0;
}

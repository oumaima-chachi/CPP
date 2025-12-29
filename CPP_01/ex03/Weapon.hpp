#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;//represente type dial arme 

public:
    Weapon(std::string type);
    const std::string& getType() const;
    void setType(std::string value);
};

#endif

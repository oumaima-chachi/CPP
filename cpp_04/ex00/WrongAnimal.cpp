#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = other.type;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some generic wrong animal sound" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return this->type;
}

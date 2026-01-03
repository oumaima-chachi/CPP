#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}  

Dog::Dog(const Dog &other) : Animal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}
       
void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
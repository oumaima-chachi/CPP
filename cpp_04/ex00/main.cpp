#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();//animal::animal()
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    std::cout << "---------------------" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();
    delete wrongMeta;
    delete wrongCat;    
    return 0;
}

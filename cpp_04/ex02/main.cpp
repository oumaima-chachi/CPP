#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    // Animal* a = new Animal();
    // a->makeSound();
    // delete a;
    // Animal* animals[4];
    // animals[0] = new Dog();
    // animals[1] = new Dog();
    // animals[2] = new Cat();
    // animals[3] = new Cat();

    // for (int i = 0; i < 4; ++i)
    //     animals[i]->makeSound();
    // for (int i = 0; i < 4; ++i)
    //     delete animals[i];
    
    // {
    //     Dog original;
    //     Dog copy = original;  // Copy constructor
    //     std::cout << "Both dogs created and copied" << std::endl;
    // }

    // {
    //     Cat cat1;
    //     Cat cat2;
    //     cat2 = cat1;  // Assignment operator
    //     std::cout << "Assignment done" << std::endl;
    // }

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not create a leak
    delete i;
    return 0;
}

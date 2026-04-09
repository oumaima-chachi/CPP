#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Derived.hpp"

Base *generate()
{
    std::srand(std::time(0));
    int r = std::rand() % 3; // 0,1,2
    if (r == 0) return new A;
    else if (r == 1) return new B;
    else return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) std::cout << "A\n";//kan essayew de convertir p en ptr ver B
    else if (dynamic_cast<B*>(p)) std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "C\n";
    else std::cout << "Unknown\n";
}

void identify(Base &p)
{
    try { A &a = dynamic_cast<A&>(p); (void)a; std::cout << "A\n"; return; }
    catch(...) {}
    try { B& b = dynamic_cast<B&>(p); (void)b; std::cout << "B\n"; return; }
    catch(...) {}
    try { C& c = dynamic_cast<C&>(p); (void)c; std::cout << "C\n"; return; }
    catch(...) {}
    std::cout << "Unknown\n";
}

int main()
{
    Base* ptr = generate();

    std::cout << "Identify via pointer: ";
    identify(ptr);

    std::cout << "Identify via reference: ";
    identify(*ptr);

    delete ptr;  
    return 0;
}
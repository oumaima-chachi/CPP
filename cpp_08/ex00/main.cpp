#include "easyfind.hpp"

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;//dynamic array container
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "Fnd: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Not fnd" << std::endl;
    }

    return 0;
}
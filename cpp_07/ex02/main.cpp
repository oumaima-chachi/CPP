#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    Array<int> arr(5);

    unsigned int i = 0;
    while (i < arr.size())
    {
        arr[i] = i * 10;
        i++;
    }

    std::cout << "Array elements:" << std::endl;
    i = 0;
    while (i < arr.size())
    {
        std::cout << arr[i] << std::endl;
        i++;
    }
    Array<int> copy = arr;
    copy[0] = 999;

    std::cout << "arr[0] = " << arr[0] << std::endl;   // 0
    std::cout << "copy[0] = " << copy[0] << std::endl; // 999

    return 0;
}
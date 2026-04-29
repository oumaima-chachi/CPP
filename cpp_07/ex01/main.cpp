#include "iter.hpp"
#include <iostream>

void printInt(const int &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    const int arr2[] = {10, 20, 30, 40};

    iter(arr, 4, printInt);
    iter(arr2, 4, printInt);

    return 0;
}
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename D>
void swap(D &a, D &b)
{
    D temp = a;
    a = b;
    b = temp;
}

template <typename D>
D min(D a, D b)
{
    if (a < b)
        return a;
    return b;
}

template <typename D>
D max(D a, D b)
{
    if (a > b)
        return a;
    return b;
}

#endif
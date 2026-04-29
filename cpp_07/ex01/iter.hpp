#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T const *arr, size_t longu, void (*f)(T const &))
{
    size_t i = 0;
    while (i < longu)
    {
        f(arr[i]);
        i++;
    }
}

#endif
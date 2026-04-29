#include <iostream>
#include "Span.hpp"

int main()
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}


// int main()
// {
//     Span sp(10000);

//     std::vector<int> v;
//     for (int i = 0; i < 10000; i++)
//         v.push_back(rand());

//     sp.addRng(v.begin(), v.end());

//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
// }
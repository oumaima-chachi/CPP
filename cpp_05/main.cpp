#include "Bureaucrat.hpp"
#include <iostream>
int main()
{
    try
    {
        Bureaucrat b("John Doe", 2);
        b.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Alice", 1);  
        std::cout << b << std::endl;  

        b.incrementGrade(); 
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
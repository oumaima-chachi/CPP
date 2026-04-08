#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b("Alice", 50);
        Form f("Contract", 40, 20);

        std::cout << b << std::endl;
        std::cout << f << std::endl;

        f.beSigned(b); // doit throw (50 > 40)
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
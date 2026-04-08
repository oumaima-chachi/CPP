#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);

    Intern someIntern;

    AForm* f1 = someIntern.makeForm("shrubbery creation", "home");
    AForm* f2 = someIntern.makeForm("robotomy request", "Bender");
    AForm* f3 = someIntern.makeForm("presidential pardon", "Marvin");
    AForm* f4 = someIntern.makeForm("unknown form", "Target");

    try 
    {   
        std::cout << std::endl;

        if (f1) boss.signForm(*f1);
        if (f2) boss.signForm(*f2);
        if (f3) boss.signForm(*f3);

        std::cout << std::endl;

        if (f1) boss.executeForm(*f1);
        if (f2) boss.executeForm(*f2);
        if (f3) boss.executeForm(*f3);

        std::cout << std::endl;
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}
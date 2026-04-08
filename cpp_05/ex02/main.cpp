#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);

    ShrubberyCreationForm f1("home");
    RobotomyRequestForm f2("Bender");
    PresidentialPardonForm f3("Marvin");

    try {    
        boss.signForm(f1);
        boss.signForm(f2);
        boss.signForm(f3);

        boss.executeForm(f1);
        boss.executeForm(f2);
        boss.executeForm(f3);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
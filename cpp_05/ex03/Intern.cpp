#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
    {
        // rien à copier
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
        const char * table[] = { "shrubbery creation", "robotomy request", "presidential pardon", NULL};

        int i = 0;
        while (i < 3)
        {
            if (formName == table[i])
                break ;
            i++;
        }
        switch (i)
        {
        case 0:
            return new ShrubberyCreationForm(target);
            break;
        case 1:
            return new RobotomyRequestForm(target);
            break ;
        default:
            return new PresidentialPardonForm(target);
            break;
        }

    std::cout << "Intern couldn't find form: " << formName << std::endl;
    return NULL;
}// factory patern 
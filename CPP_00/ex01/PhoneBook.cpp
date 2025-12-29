#include "PhoneBook.hpp"
#include <iomanip>


PhoneBook::PhoneBook() : count(0) {}

void PhoneBook::addContact(Contact c)
{
    contacts[count % 8] = c;
    count++;
}

void PhoneBook::showContacts() const// read only 
{
    std ::cout << std::setw(10) << "Index" << "|"
               << std::setw(10) << "First Name" << "|"
               << std::setw(10) << "Last Name" << "|"
               << std::setw(10) << "Nickname" << "\n";
    std::cout << ".........................................." << "\n";
    int size ;
    if (count < 8)
        size = count;
    else
        size = 8;
    int i;
    i = 0;
    while (i < size)
    {
        std::string fn = contacts[i]. getFirstName();
        std::string ln = contacts[i]. getLastName();
        std::string nn = contacts[i]. getNickName();
        if (fn.length() > 10)
            fn = fn.substr(0, 9) + ".";
        if (ln.length() > 10)
            ln = ln.substr(0, 9) + ".";
        if (nn.length() > 10)
            nn = nn.substr(0, 9) + ".";
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << fn << "|"
                  << std::setw(10) << ln << "|"
                  << std::setw(10) << nn << "\n";
        i++;
    }  
}

void PhoneBook::showContact(int index) const
{
    int size;
    if (count < 8)
        size = count;
    else
        size = 8;
    if (index < 0 || index >= size)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

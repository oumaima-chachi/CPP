#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>

int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    while (true)
    {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof())
        {
            std::cout << "\nExiting..." << std::endl;
            break;
        }

        if (command == "ADD")
        {
            Contact c;
            std::string input;

            std::cout << "First name: ";
            std::getline(std::cin, input);
            c.setFirstName(input);

            std::cout << "Last name: ";
            std::getline(std::cin, input);
            c.setLastName(input);

            std::cout << "Nickname: ";
            std::getline(std::cin, input);
            c.setNickName(input);

            std::cout << "Phone number: ";
            std::getline(std::cin, input);
            c.setPhoneNumber(input);

            std::cout << "Darkest secret: ";
            std::getline(std::cin, input);
            c.setDarkestSecret(input);

            phonebook.addContact(c);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH")
        {
            phonebook.showContacts();
            std::cout << "Enter index to view details: ";
            std::getline(std::cin, command);

            if (!command.empty() && isdigit(command[0]))
                phonebook.showContact(atoi(command.c_str()));
            else
                std::cout << "Invalid index input!" << std::endl;
        }
        else if (command == "EXIT")//overloading
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Unknown command. Try again!" << std::endl;
        }
    }

    return 0;
}

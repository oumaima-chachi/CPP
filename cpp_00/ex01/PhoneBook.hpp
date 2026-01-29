#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private: 
    Contact contacts[8];
    int count; 
public:
    PhoneBook();  
    void addContact(Contact c);
    void showContacts() const; 
    void showContact(int index) const; 
};

#endif

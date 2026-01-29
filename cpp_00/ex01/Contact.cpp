#include "Contact.hpp"

void Contact::setFirstName(std::string name)//:: is scope resulution 
{
    first_name = name;
}

void Contact::setLastName(std::string name)
{
    last_name = name;
}

void Contact::setNickName(std::string name)
{
    nickname = name;
}

void Contact::setPhoneNumber(std::string number)
{
    phone_number = number;
}

void Contact::setDarkestSecret(std::string name)
{
    darkest_secret = name;
}

std::string Contact::getFirstName() const
{
    return first_name;
}

std::string Contact::getLastName() const
{
    return last_name;
}

std::string Contact::getNickName() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phone_number;
}

std::string Contact::getDarkestSecret() const {
    return darkest_secret;
}

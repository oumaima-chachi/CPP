#ifndef CONTACT_HPP
# define CONTACT_HPP 

#include <iostream>
// #include <string>

class Contact
{
    private : 
        std::string first_name; 
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public :
        void setFirstName(std::string name); 
        void setLastName(std::string name);
        void setNickName(std::string name);
        void setPhoneNumber(std::string number);
        void setDarkestSecret(std::string name);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif
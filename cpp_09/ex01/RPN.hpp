#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>

class RPN 
{
    public:
        static int evaluate(const std::string& expression);
};

#endif
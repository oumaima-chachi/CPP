#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>

int RPN::evaluate(const std::string &expression)
{
    std::stack<int> st;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) 
    {
        if (token.length() == 1 && isdigit(token[0])) 
        {
            st.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") 
        {
            if (st.size() < 2)
                throw std::runtime_error("Error");
            int b = st.top(); 
            st.pop();
            int a = st.top(); 
            st.pop();
            int result;
            if (token == "+") 
                result = a + b;
            else if (token == "-") 
                result = a - b;
            else if (token == "*") 
                result = a * b;
            else 
            {
                if (b == 0)
                    throw std::runtime_error("Error");
                result = a / b;
            }
            st.push(result);
        }
        else 
        {
            throw std::runtime_error("Error");
        }
    }
    if (st.size() != 1)
        throw std::runtime_error("Error");
    return st.top();
}
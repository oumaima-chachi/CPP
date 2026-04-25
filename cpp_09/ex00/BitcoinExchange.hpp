#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;

    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void loadDataBase(const std::string &filename);
        void processInput(const std::string &filename);

        std:: string trim(const std::string &str);

        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value);
};
#endif
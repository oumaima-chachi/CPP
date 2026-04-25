#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t start = 0;
    size_t end = str.length();

    while (start < str.length() && (str[start] == ' ' || str[start] == '\t'))
        start++;
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
        end--;
    return str.substr(start, end - start);
}

void BitcoinExchange::loadDataBase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string rate;
        if (std::getline(ss, date, ',') && std::getline(ss, rate))
        {
            date = trim(date);
            rate = trim(rate);
            _data[date] = std::atof(rate.c_str());
        }
    }
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    if (!std::getline(file, line))
        return;
    if (line != "date | value")
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = trim(date);
        valueStr = trim(valueStr);
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidValue(valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        double value = std::atof(valueStr.c_str());

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, double>::iterator it;
        it = _data.lower_bound(date);

        if (it == _data.end() || it->first != date)
        {
            if (it == _data.begin())
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            it--;
        }
        double result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10)
        return false;

    int i = 0;
    while (i < 10)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (!isdigit(date[i]))
                return false;
        }
        i++;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDay = 30;
    if (month == 2)
    {
        if (year % 4 == 0)
            maxDay = 29;
        else
            maxDay = 28;
    }
    if (day > maxDay)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
    if (value.empty())
        return false;

    int i = 0;
    int dot = 0;

    if (value[0] == '-')
        i = 1;

    while (i < (int)value.length())
    {
        if (value[i] == '.')
        {
            dot++;
            if (dot > 1)
                return false;
        }
        else
        {
            if (!isdigit(value[i]))
                return false;
        }
        i++;
    }

    return true;
}
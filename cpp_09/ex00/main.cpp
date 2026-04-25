#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usg: impossi :(" << std::endl;
        return 1;
    }
    BitcoinExchange btc;

    btc.loadDataBase("data.csv");
    btc.processInput(argv[1]);

    return 0;
}
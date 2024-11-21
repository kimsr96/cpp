#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <map>
#include <cstdlib>

class BitcoinExchange{
    private:
        std::map<std::string, float>    _map;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &copy);
        BitcoinExchange &operator=(BitcoinExchange const &copy);
        void    validInputData(char *fileName);
        void    exchanger();
};

#endif
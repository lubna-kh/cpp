#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void readData(const std::string &filename);
        void compareDate(const std::string &line,const std::string &date, const float &value);
        void findNearestDate(const std::string &date, const float &value);
};

#endif
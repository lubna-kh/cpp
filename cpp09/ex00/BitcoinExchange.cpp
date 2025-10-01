#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
    std::string line;
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: Could not open file.");
    }
    getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;
        getline(ss, date, ',');
        getline(ss, value);
        data[date] = std::strtof(value.c_str(), NULL);
    }
    file.close();
}

static bool checkDate(const std::string &date, const std::string &line)
{
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    else if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    else if ((month == 1 || month == 3 || month == 5 || month == 7
            || month == 8 || month == 10 || month == 12)
            && day > 30)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    else if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeap && day > 29) || (!isLeap && day > 28))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return false;
        }
    }
    return true;
}

static bool checkData(const std::string &line,const std::string &date, const float &value)
{
    (void) value;
    if (!checkDate(date, line))
        return false;
    for (size_t i = 0; i < date.length(); i++)
    {
        if (date[i] == '-')
            continue;
        if (!isdigit(date[i]) && date[i] != ' ')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            return false;
        }
    }
    return true;
}

static int getDate(const std::string &date, char c)
{
    int n = 0;

    if (c == 'y')
        n = std::atoi(date.substr(0, 4).c_str());
    if (c == 'm')
        n = std::atoi(date.substr(5, 2).c_str());
    if (c == 'd')
        n = std::atoi(date.substr(8, 2).c_str());
    // std::cout<< "n:"<<n <<std::endl;
    // exit(1);
    return n;
}


void BitcoinExchange::findNearestDate(const std::string &date, const float &value)
{
    (void) value;
    std::map<std::string,float>::iterator it = data.begin();
    // for (it = data.begin();it != data.end();it++)
    // {
        while (getDate(it->first, 'y') <= getDate(date, 'y') && it != data.end())
        {
            it++;
        }
        if (it != data.end())
        {

            while (getDate(it->first, 'm') <= getDate(date, 'm') && it != data.end())
            {
                it++;
            }
            if (it != data.end())
            {
                std::cout<<"it->first:"<< it->first <<std::endl;
                while (getDate(it->first, 'd') <= getDate(date, 'd') && it != data.end())
                {
                    it++;
                }
                // if (it != data.end())
                //     break;
            }
        }
    // }
    if (it != data.begin())
        it--;
    std::cout<<date<<" => "<<value<<" = "<< it->second * value <<std::endl;
}

void BitcoinExchange::compareDate(const std::string &line,const std::string &date, const float &value)
{
    (void) line;
    std::map<std::string,float>::iterator it;
    for (it = data.begin();it != data.end();it++)
    {
        if (getDate(it->first, 'y') == getDate(date, 'y'))
        {
            if (getDate(it->first, 'm') == getDate(date, 'm'))
            {
                if (getDate(it->first, 'd') == getDate(date, 'd'))
                {
                    std::cout<<date<<" => "<<value<<" = "<< it->second * value <<std::endl;
                    return;
                }
            }
        }
    }
    findNearestDate(date, value);
}

static void rmSpaces(std::string &str)
{
    std::string tmp;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            tmp += str[i];
    }
    str = tmp;
}

void BitcoinExchange::readData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: Could not open file.");
    }
    std::string line;
    getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;
        getline(ss, date, '|');
        getline(ss, value);
        rmSpaces(date);
        rmSpaces(value);
        // std::cout<<"date:"<< date <<".\n";
        // std::cout<<"value:"<< value <<".\n";
        float val = std::strtof(value.c_str(), NULL);
        if (!checkData(line, date, val))
            continue;
        compareDate(line, date, val);
    }
    file.close();
}
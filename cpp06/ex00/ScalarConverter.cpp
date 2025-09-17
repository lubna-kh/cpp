#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

void    ScalarConverter::Digit(double nb)
{
    if (nb >= 32 && nb <= 126)
        std::cout<<"char: '"<< static_cast<char>(nb) <<"'"<<std::endl;
    else if (nb < 0 || nb > 127)
        std::cout<<"char: impossible"<<std::endl;
    else
        std::cout<<"char: Non displayable"<<std::endl;
    if (nb >= INT_MAX || nb <= INT_MIN)
        std::cout<<"int: impossible"<<std::endl;
    else
        std::cout<<"int: "<< static_cast<int>(nb) <<std::endl;
    if (nb >= FLT_MAX || nb <= FLT_MIN)
        std::cout<<"float: impossible"<<std::endl;
    else
        std::cout<<"float: "<< std::fixed << std::setprecision(1)<<static_cast<float>(nb)<<"f"<<std::endl;
    std::cout<<"double: "<<std::fixed << std::setprecision(1)<<nb<<std::endl;
}

bool    ScalarConverter::pseudoLiterals(const std::string &c)
{
    if (c == "nanf" || c == "nan")
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: nanf"<<std::endl;
        std::cout<<"double: nan"<<std::endl;
        return true;
    }
    else if (c == "+inff" || c == "+inf")
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: +inff"<<std::endl;
        std::cout<<"double: +inf"<<std::endl;
        return true;
    }
    else if (c == "-inff" || c == "-inf")
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: -inff"<<std::endl;
        std::cout<<"double: -inf"<<std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::convert(std::string c)
{

    std::istringstream iss(c);
    double nb;
    iss >> nb;
    if (!iss.fail())
    {
        std::string c;
        iss >> c;
        if ((c.length() == 1 && c[0] == 'f') || c.length() == 0)
        {
            Digit(nb);
        }
        else
            std::cout<<"Invalid\n";
    }
    else if (c.length() == 1 && !isdigit(c[0]))
    {
        nb = static_cast<double>(c[0]);
        Digit(nb);
    }
    else if (pseudoLiterals(c))
        return ;
    else
        std::cout<<"Invalid\n";
}
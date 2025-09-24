#include "ScalarConverter.hpp"
#include <algorithm>

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

static bool    pseudoLiterals(const std::string &c)
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

static void    Digit(double nb)
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
    float f = std::numeric_limits<float>::max();
    if (nb >= f || nb <= -f)
        std::cout<<"float: impossible"<<std::endl;
    else
        std::cout<<"float: "<< std::fixed << std::setprecision(1)<<static_cast<float>(nb)<<"f"<<std::endl;
    std::cout<<"double: "<<std::fixed << std::setprecision(1)<<nb<<std::endl;
}

static bool isValidFloat(const std::string &c)
{
    size_t i = 0;
    if (c[i] == '+' || c[i] == '-')
        i++;
    bool pointSeen = false;
    bool digitSeen = false;
    for (; i < c.length(); i++)
    {
        if (isdigit(c[i]))
            digitSeen = true;
        else if (c[i] == '.')
        {
            if (pointSeen)
                return false;
            pointSeen = true;
        }
        else if (c[i] == 'f' && pointSeen)
            return true;
        else
            return false;
    }
    return digitSeen;
}

void ScalarConverter::convert(std::string c)
{
    std::string tmp = c;
    std::istringstream iss(c);
    double nb;
    iss >> nb;
    if (!iss.fail())
    {
        std::string rem;
        iss >> rem;
        if (((rem.length() == 1 && rem[0] == 'f') || rem.length() == 0) && iss.eof() && isValidFloat(tmp))
        {
            Digit(nb);
        }
        else
        {
            std::cout<<"char: impossible"<<std::endl;
            std::cout<<"int: impossible"<<std::endl;
            std::cout<<"float: impossible"<<std::endl;
            std::cout<<"double: impossible"<<std::endl;
        }
    }
    else if (c.length() == 1 && !isdigit(c[0]))
    {
        nb = static_cast<double>(c[0]);
        Digit(nb);
    }
    else if (pseudoLiterals(c))
        return ;
    else
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: impossible"<<std::endl;
        std::cout<<"double: impossible"<<std::endl;
    }
}

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <limits.h>
#include <float.h>
#include <iomanip>



class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();
        static void convert(std::string c);
        static void    Digit(double nb);
        static bool pseudoLiterals(const std::string &c);
};

#endif
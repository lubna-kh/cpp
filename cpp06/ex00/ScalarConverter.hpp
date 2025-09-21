#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <limits>
#include <limits.h>
#include <float.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>



class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();
    public:
        static void convert(std::string c);
        static void    Digit(double nb);
        static bool pseudoLiterals(const std::string &c);
        static bool isValidFloat(const std::string &c);
};

#endif
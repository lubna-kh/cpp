#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const std::string &input) : input(input)
{}

RPN::RPN(const RPN &other)
{

}

RPN &RPN::operator=(const RPN &other)
{

}

RPN::~RPN()
{

}

void RPN::start()
{
    for (size_t i = 0;input[i];i++)
    {
        if (input[i] == ' ')
            i++;
        if (!isdigit(input[i]))
            return;
        else
        {
            s.push(input[i]);
            i++;
        }
        
        
    }
}
#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const std::string &input) : input(input) {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->input = other.input;
    return *this;
}

RPN::~RPN() {}

static bool isOperator(const char c, Operator &o)
{
    if (c == '*' || c == '/' || c == '+' || c == '-')
    {
        if (c == '*')
            o = MULTIPLICATION;
        if (c == '/')
            o = DIVISION;
        if (c == '-')
            o = SUBTRACTION;
        if (c == '+')
            o = ADDITION;
        return true;
    }
    return false;
}

bool RPN::handleOperator(const Operator &o, bool &valid)
{
    if (s.size() < 2)
    {
        std::cout<<"Error\n";
        return false;
    }
    valid = true;
    int a = s.top();
    s.pop();

    int b = s.top();
    s.pop();    
    if (o == 0)
    {
        s.push(a + b);
    }
    if (o == 1)
        s.push(b - a);
    if (o == 2)
        s.push(a * b);
    if (o == 3)
    {
        if (a == 0)
        {
            std::cout<<"Error: Division by Zero!\n";
            return false;
        }
        s.push(b / a);
    }
    return true;
}

void RPN::start()
{
    Operator o = ADDITION;
    bool valid = false;
    for (size_t i = 0;input[i];i++)
    {
        while (input[i] == ' ' && input[i])
            i++;
        if (!input[i])
            break ;
        if (isdigit(input[i]))
            s.push(input[i] - '0');
        else if (!isOperator(input[i], o))
        {
            std::cout<<"Error\n";
            return ;
        }
        else //operator
        {
            if (!handleOperator(o, valid))
                return ;
        }
    }
    if (s.size() != 1 || !valid)
    {
        std::cout<<"Error\n";
        return ;
    }
    std::cout<<s.top()<<std::endl;
}
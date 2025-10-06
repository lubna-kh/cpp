#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

enum Operator
{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
};

class RPN
{
    private:
        std::stack<int> s;
        std::string input;
    public:
        RPN();
        RPN(const std::string &input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void start();
        bool handleOperator(const Operator &oo, bool &valid);

};

#endif
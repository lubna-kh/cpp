#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat obj("lubna", 150);
        // obj.decrementGrade();
        obj.incrementGrade();
        obj.incrementGrade();
        obj.incrementGrade();
        std::cout<< obj;
    }
    catch(const std::exception& err)
    {
        std::cerr << err.what() << '\n';
    }    
    return 0;
}
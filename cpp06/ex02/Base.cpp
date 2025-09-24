#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base * generate(void)
{
        int n;

        n = std::rand() % 3;
        if (n == 0)
                return (new (std::nothrow) A());
        else if (n == 1)
                return (new (std::nothrow) B());
        else
                return (new (std::nothrow) C());
}

void identify(Base* p)
{
        if (dynamic_cast<A*>(p))
                std::cout << "A" << std::endl;
        else if (dynamic_cast<B*>(p))
                std::cout << "B" << std::endl;
        else if (dynamic_cast<C*>(p))
                std::cout << "C" << std::endl;
        else
                std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p)
{
        try
        {
                A &a = dynamic_cast<A&>(p);
                (void)a;
                std::cout << "Its A" << std::endl;
                return;
        }
        catch (...)
        {
                std::cout<<"Its not A."<<std::endl;
        }
        try
        {
                B &b = dynamic_cast<B&>(p);
                (void)b;
                std::cout << "Its B" << std::endl;
                return;
        }
        catch (...)
        {
                std::cout<<"Its not B."<<std::endl;
        }
        try
        {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "Its C" << std::endl;
                return;
        }
        catch (...)
        {
                std::cout<<"Its not C."<<std::endl;
        }
        std::cout << "Its Unknown Type" << std::endl;

}
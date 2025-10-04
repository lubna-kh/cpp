#include "Span.hpp"
#include <cstdlib>
#include <ctime>
int main()
{
    // srand(time(NULL));
    
    // std::vector<int> tmp_v;
    // for (int i=0;i < 10000;i++)
    //     tmp_v.push_back(rand() % 10000);
    // // for (int i=0;i < 10000;i++)
    // //     std::cout<< tmp_v[i] <<std::endl;
    // Span sp = Span(10000);
    // try
    // {
    //     // for (int i=0;i < 10000;i++)
    //     //     sp.addNumber(tmp_v[i]);
    //     sp.addNumber(tmp_v.begin(), tmp_v.end());
    //     std::cout << sp.shortestSpan() << std::endl;
    //     std::cout << sp.longestSpan() << std::endl;
    // }
    // catch(const std::exception &e)
    // {
    //     std::cerr<<e.what()<<std::endl;
    // }

    {


        Span sp = Span(7);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(0);
        sp.addNumber(-1);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    return 0;
}
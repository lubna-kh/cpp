#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    std::list<int> l;
    l.push_back('j');
    l.push_back('d');
    l.push_back('s');
    l.push_back('c');
    l.push_back('w');
    
    std::stack<int> s;
    s.push(45);
    s.push(9);
    s.push(4);
    s.push(3);


    try
    {
        
        std::vector<int>::iterator it1 = easyfind(v,4);
        std::cout << (*it1) << std::endl;
        std::list<int>::iterator it2 = easyfind(l,'d');
        std::cout << (*it2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
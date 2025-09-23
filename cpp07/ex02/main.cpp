#include "Array.hpp"

int main()
{
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " "; 
    std::cout << std::endl;

    a[2] = 42;
    std::cout << a[2] << std::endl;

    try
    {
        std::cout << a[10] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Out of bounds!" << std::endl;
    }

    Array<int> b = a;
    // b[2] = 100;
    // std::cout << a[2] << std::endl;
}

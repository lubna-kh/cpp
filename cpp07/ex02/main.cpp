#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#define MAX_VAL 750
int main(int, char**)
{
    // Array<int> a;
    // std::cout << "Size of a: " << a.size() << std::endl;
    // try
    // {
    //     Array<int> a(0);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;

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
    b[2] = 100;
    std::cout << a[2] << std::endl;
    return 0;
}
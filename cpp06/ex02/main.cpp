#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>

int main()
{
        std::srand(std::time(NULL));

        std::cout << "Generating and identifying 5 random objects:" << std::endl;
        for (int i = 0; i < 5; i++)
        {
                std::cout << "Test " << i + 1 << ":" << std::endl;
                Base* obj = generate();
                if (!obj)
                {
                        std::cerr << "Memory allocation failed" << std::endl;
                        return 1;
                }
                std::cout << "Identifying using pointer: ";
                identify(obj);
                std::cout << "Identifying using reference:\n";
                identify(*obj);
                delete obj;
        }

        // std::cout << "=== Testing NULL pointer ===" << std::endl;
        // Base* nullPtr = NULL;
        // std::cout << "Identifying NULL pointer: ";
        // identify(nullPtr);
        // std::cout << "Identifying NULL reference:\n";
        // identify(*nullPtr);

        // std::cout << "=== Testing Explicit Types ===" << std::endl;
        // Base* a = new A();
        // Base* b = new B();
        // Base* c = new C();

        // std::cout << "Testing A:" << std::endl;
        // std::cout << "By pointer: ";
        // identify(a);
        // std::cout << "By reference: ";
        // identify(*a);

        // std::cout << "Testing B:" << std::endl;
        // std::cout << "By pointer: ";
        // identify(b);
        // std::cout << "By reference: ";
        // identify(*b);

        // std::cout << "Testing C:" << std::endl;
        // std::cout << "By pointer: ";
        // identify(c);
        // std::cout << "By reference: ";
        // identify(*c);

        // delete a;
        // delete b;
        // delete c;
        return 0;
}
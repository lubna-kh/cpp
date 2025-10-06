#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout<<"Error\n";
        return 1;
    }
    PmergeMe pmergeme;
    pmergeme.start(argc, argv);
    return 0;
}
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // std::vector<int>::iterator it;
    //i can comment this line and write auto word before it
    //so the compiler will know that its an iterator

    for(auto it=numbers.begin() + 2;it < numbers.end() -1;it += 2)
    {
        std::cout<< *it<< " ";
    }
    std::cout<< std::endl;

    //Another way
    // for (auto &element: numbers)
    // {
    //     std::cout<< element<<std::endl;
    // }

    //Reverse iterator
    // std::vector<int>::reverse_iterator it;
    // for (auto it = numbers.rbegin(); it != numbers.rend(); it++)
    // {
    //     std::cout<< *it<< " ";
    // }

}
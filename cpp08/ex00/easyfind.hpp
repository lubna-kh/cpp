#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>


// template <typename T>
// typename T::iterator easyfind(T lst, int n)
// {
//     return std::find(lst.begin(), lst.end(), n);
// }

template <typename T>
typename T::iterator easyfind(T& lst, int n)
{
    typename T::iterator it = std::find(lst.begin(), lst.end(), n);
    if (it == lst.end())
        throw std::runtime_error("Argument not found!");
    else
        return it;
}
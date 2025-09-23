#include "iter.hpp"


void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
    std::cout << "toLower: " << arr << std::endl;
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
    std::cout << "toUpper: " << arr << std::endl;
}

void ft_decrement(int &num)
{
    num--;
    std::cout << "After decrement: " << num << std::endl;
}

template<typename T>
void ft_print(const T &c)
{
    std::cout << c << std::endl;
}

int main()
{
    //const example
    const char arr[] = {'H', 'e', 'l', 'l', 'o'};
    ::iter(arr, 5, ft_print<char>);
    std::cout << "---------------------" << std::endl;

    // // Example with int array
    int tab[] = {0, 1, 2, 3, 4};
    ::iter(tab, 5, ft_decrement);
    std::cout << "---------------------" << std::endl;

    // Example with char array
    char tab2[] = {'a', 'b', 'c', 'd', 'e'};
    ::iter(tab2, 5, ft_toupper);

    std::cout << "---------------------" << std::endl;

    ::iter(tab2, 5, ft_print<char>);
    std::cout << "---------------------" << std::endl;
    ::iter(tab2, 5, ft_tolower);
    return 0;
}
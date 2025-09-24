#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    std::cout<< "Default Constructor called" << std::endl;
    arr = NULL;
    len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    std::cout<< "Parametrized Constructor called" << std::endl;
    len = n;
    arr = new (std::nothrow) T[n];
    if (!arr)
    {
        std::cerr << "Memory allocation failed" << std::endl;
        len = 0;
        return;
    }
    for (unsigned int i = 0; i < len; i++)
        arr[i] = T();
        //here if the T is int it will be initilized to 0
        //if it is string it till be empty string 
        //if its a class it will call the default construtor for it
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
    std::cout<< "Copy Constructor called" << std::endl;
    this->len = other.len;
    this->arr = new(std::nothrow) T[other.len];
    if (!this->arr)
    {
        std::cerr << "Memory allocation failed" << std::endl;
        this->len = 0;
        return;
    }
    for (unsigned int i = 0; i < len; i++)
        this->arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    std::cout<< "Copy Assignment Constructor called" << std::endl;
    if (this != &other)
    {
        delete[] this->arr;
        this->len = other.len;
        this->arr = new (std::nothrow) T[other.len];
        if (!this->arr)
        {
            std::cerr << "Memory allocation failed" << std::endl;
            this->len = 0;
            return *this;
        }
        for (unsigned int i = 0; i < other.len; i++)
            this->arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return len;
}

template <typename T>
Array<T>::~Array()
{
    std::cout<< "Destructor called" << std::endl;
    delete[] this->arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= len)
        throw std::out_of_range("Index out of range");
    return arr[index];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &arr)
{
    for (unsigned int i = 0; i < arr.size(); i++)
        os << arr[i] << " ";
    return os;
}
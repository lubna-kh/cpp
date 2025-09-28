#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int len;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T> &other);
        Array<T> &operator=(const Array<T> &other);
        T &operator[](unsigned int index);
        T &operator[](unsigned int index) const;
        ~Array();

        unsigned int size() const;
};

// template <typename T>
// std::ostream &operator<<(std::ostream &os, const Array<T> &arr);

#include "Array.tpp"
#endif
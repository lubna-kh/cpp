#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>


template<typename T, typename F>
void iter(T *array, size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

template<typename T, typename F>
void iter(const T *array, size_t len, const F func)
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}




// How it Works?
// T* array can be either T* (non-const) or const T*.
// Func func can be any callable: regular function, lambda, or function template.
// When you call func(array[i]):
// If array is const T*, array[i] is const T& → func must accept const T&.
// If array is T*, array[i] is T& → func can accept T&.
// The compiler deduces the type automatically from the array.


#endif
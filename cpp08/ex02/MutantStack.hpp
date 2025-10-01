#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:

        MutantStack() : std::stack<T, Container>(){} // this will call the default constructor of the base class
        MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
        MutantStack &operator=(const MutantStack &other)
        {
            if (this != &other)
            {
                std::stack<T, Container>::operator=(other);
                // or
                // this->c = other.c;
            }
            return *this;
        }
        ~MutantStack(){}


        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;


        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        const_iterator cbegin() const
        {
            return this->c.begin();
        }
        const_iterator cend() const
        {
            return this->c.end();
        }
        const_reverse_iterator crbegin() const
        {
            return this->c.rbegin();
        }
        const_reverse_iterator crend() const
        {
            return this->c.rend();
        }
        reverse_iterator rbegin()
        {
            return this->c.rbegin();
        }
        reverse_iterator rend()
        {
            return this->c.rend();
        }
};

#endif
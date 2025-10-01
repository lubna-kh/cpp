#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other)
{
    this->N = other.N;
    this->v = other.v;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->v = other.v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if ((unsigned int)v.size() == N)
        throw std::out_of_range("Span is Full!!");
    v.push_back(n);
    std::sort(v.begin(), v.end());
}

unsigned int Span::shortestSpan()
{
    if (v.size() < 2)
        throw std::out_of_range("Not enough elements to find a span");
    return (*(v.begin() + 1) - *v.begin());
}

unsigned int Span::longestSpan()
{
    if (v.size() < 2)
        throw std::out_of_range("Not enough elements to find a span");
    return (*(v.end() - 1) - *(v.begin()));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    // for (std::vector<int>::iterator it = begin; it != end;it++)
    // {
    //     if ((unsigned int)v.size() >= N)
    //         throw std::out_of_range("Span is Full!!");
    //     addNumber(*it);
    // }
    std::sort(begin, end);
    if (v.size() + std::distance(begin, end) > N)
        throw std::out_of_range("Span is Full!!");
    v.insert(v.end(), begin, end);
}
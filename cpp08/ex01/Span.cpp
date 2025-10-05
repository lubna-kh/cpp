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


// unsigned int Span::shortestSpan()
// {
//     if (v.size() < 2)
//         throw std::out_of_range("Not enough elements to find a span");
//     unsigned int min = UINT_MAX;
//     for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1; it++)
//     {
//         long long diff = static_cast<long long>(*(it + 1)) - static_cast<long long>(*it);
//         if (diff < 0)
//             diff = -diff;
//         min = std::min(min, static_cast<unsigned int>(diff));
//         if (min == 0)
//             break;
//     }
//     return min;
// }

// unsigned int Span::longestSpan()
// {
//     if (v.size() < 2)
//         throw std::out_of_range("Not enough elements to find a span");
//     long long diff = static_cast<long long>(*(v.end() - 1)) - static_cast<long long>(*v.begin());
//     if (diff < 0)
//         diff = -diff;
//     return static_cast<unsigned int>(diff);
// }

unsigned int Span::shortestSpan()
{
    if (v.size() < 2)
        throw std::out_of_range("Not enough elements to find a span");
    unsigned int min = 4294967295;
    for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1;it++)
    {
        min = std::min(min, (((unsigned int)(*(it + 1))) - (*it)));
        if (min == 0)
            break;
    }
    return (min);
}

unsigned int Span::longestSpan()
{
    if (v.size() < 2)
        throw std::out_of_range("Not enough elements to find a span");
    return (static_cast<unsigned int>(*(v.end() - 1) - *(v.begin())));
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
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
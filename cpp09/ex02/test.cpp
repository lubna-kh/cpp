#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->v = other.v;
    this->d = other.d;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->v = other.v;
        this->d = other.d;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::checkArgs(char **av)
{
    for (size_t i = 1; av[i]; i++)
    {
        for (size_t j = 0; av[i][j]; j++)
        {
            if (!isdigit(av[i][j]) && av[i][j] != '+')
            {
                std::cout<<"Error\n";
                return true;
            }
        }
    }
    for (size_t i = 1; av[i]; i++)
    {
        int num = atoi(av[i]);
        v.push_back(num);
        d.push_back(num);
    }
    return false;
}


template<typename matrixCon, typename container>
void    PmergeMe::buildChain(matrixCon matrix, container &mainChain,container &smallerChain)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        mainChain.push_back(matrix[i][1]);
        smallerChain.push_back(matrix[i][0]);
    }
}

template<typename container>
container    PmergeMe::jacobsthalLinear(size_t n)
{
    container jacobsthal;
    jacobsthal.push_back(0);
    if (n > 1)
        jacobsthal.push_back(1);
    while (true)
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= n)
            break ;
        jacobsthal.push_back(next);
    }
    for (size_t i = 0;i < n;i++)
    {
        if(std::find(jacobsthal.begin(), jacobsthal.end(), i) == jacobsthal.end())
            jacobsthal.push_back(i);
    }
    return jacobsthal;
}

void    PmergeMe::sortVector(std::vector<int> &v)
{
    if (v.size() <= 1)
        return ;
    std::vector<std::vector<int> > matrix;
    std::vector<int> mainChain;
    std::vector<int> smallerChain;
    int leftOver = -1;

    for(size_t i= 0; i + 1 < v.size();i+=2)
    {
        std::vector<int> pair;
        pair.push_back(v[i]);
        pair.push_back(v[i + 1]);
        if (v[i] > v[i + 1])
        {
            std::swap(pair[0], pair[1]);
        }
        matrix.push_back(pair);
    }
    if (v.size() % 2 != 0)
        leftOver = v[v.size() - 1];
    buildChain(matrix, mainChain, smallerChain);
    sortVector(mainChain);
    std::vector<int> jacobsthal = jacobsthalLinear<std::vector<int> >(smallerChain.size());
    for (size_t i = 0;i < smallerChain.size();i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(),smallerChain[jacobsthal[i]]);
        mainChain.insert(pos,smallerChain[jacobsthal[i]]);
    }
    if (leftOver != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftOver);
        mainChain.insert(pos, leftOver);
    }
    v = mainChain;
}

void    PmergeMe::sortDeque(std::deque<int> &d)
{
    if (d.size() <= 1)
        return ;
    std::deque<std::deque<int> > matrix;
    std::deque<int> mainChain;
    std::deque<int> smallerChain;
    int leftOver = -1;

    for(size_t i= 0; i + 1 < d.size();i+=2)
    {
        std::deque<int> pair;
        pair.push_back(d[i]);
        pair.push_back(d[i + 1]);
        if (d[i] > d[i + 1])
        {
            std::swap(pair[0], pair[1]);
        }
        matrix.push_back(pair);
    }
    if (d.size() % 2 != 0)
        leftOver = d[d.size() - 1];
    buildChain(matrix, mainChain, smallerChain);
    sortDeque(mainChain);
    std::deque<int> jacobsthal = jacobsthalLinear<std::deque<int> >(smallerChain.size());
    for (size_t i = 0;i < smallerChain.size();i++)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(),smallerChain[jacobsthal[i]]);
        mainChain.insert(pos,smallerChain[jacobsthal[i]]);
    }
    if (leftOver != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftOver);
        mainChain.insert(pos, leftOver);
    }
    std::cout<<"hi\n";
    d = mainChain;
}

void PmergeMe::start(int ac, char **av)
{
    (void)ac;
    if(checkArgs(av))
        return ;
    std::cout<<"Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout<<v[i]<<" ";
    std::cout<<"\n";
    //sorting part to be added here
    // struct timeval startV, endV;
    // gettimeofday(&startV, NULL);
    sortVector(v);
    // gettimeofday(&endV, NULL);
    // struct timeval startD, endD;
    // gettimeofday(&startD, NULL);
    // sortDeque(d);
    // gettimeofday(&endD, NULL);

    std::cout<<"After: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout<<v[i]<<" ";
    std::cout<<"\n";

    // double timeV = ((endV.tv_sec  - startV.tv_sec) * 1e6 + (endV.tv_usec - startV.tv_usec));
    // double timeD = ((endD.tv_sec  - startD.tv_sec) * 1e6 + (endD.tv_usec - startD.tv_usec));
    // std::cout<< std::fixed << std::setprecision(5);
    // std::cout<<"Time to process a range of "<<ac - 1<<" elements with std::vector : "<< timeV <<" us"<<std::endl;
    // std::cout<<"Time to process a range of "<<ac - 1<<" elements with std::deque : "<< timeD <<" us"<<std::endl;

}

#ifndef PMERGEMME_HPP
#define PMERGEMME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>// atoi
#include <sys/time.h>// gettimeofday
#include <iomanip>// std::setprecision
#include <algorithm>// std::find

//insert at front for deque : O(1)
//insert at front for vector : O(n)

class PmergeMe
{
    private:
        std::vector<int> v;
        std::deque<int> d;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool    checkArgs(char **av);
        void    start(int ac, char **av);
        void    sortVector(std::vector<int> &v);
        void    sortDeque(std::deque<int> &v);

        template<typename matrixCon, typename container>
        void    buildChain(matrixCon matrix, container &mainChain,container &smallerChain);

        template<typename container>
        container    jacobsthalLinear(size_t n);
};

#endif
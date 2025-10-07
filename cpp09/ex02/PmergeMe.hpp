#ifndef PMERGEMME_HPP
#define PMERGEMME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>// atoi
#include <sys/time.h>// gettimeofday
#include <iomanip>// std::setprecision

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
        void    buildChain(std::vector<std::vector<int> > matrix,std::vector<int> &mainChain,std::vector<int> &smallerChain);
        // void    jacobsthalLinear(std::vector<int> &mainChain,std::vector<int> &smallerChain,int leftOver);
};

#endif
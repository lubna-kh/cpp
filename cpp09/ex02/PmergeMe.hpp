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

        void start(int ac, char **av);
        template <typename T>
        void    sortMerge(T &container, int left, int right);
        template <typename T>
        void    merge(T &container, int left, int mid, int right);
};

#endif
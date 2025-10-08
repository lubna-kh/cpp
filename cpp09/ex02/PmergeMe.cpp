#include "PmergeMe.hpp"
// std::vector<int> PmergeMe::jacobsthalLinear(size_t n)
// {
//     size_t i = 0;
//     size_t j = 1;
//     std::vector<int> jacobsthal;
//     jacobsthal.push_back(i);
//     while (j < n)
//     {
//         jacobsthal.push_back(j);
//         size_t next = j + 2 * i + 1; i++;
//         j = next;
//     }
//     for (size_t i = 0;i < n;i++)
//     {
//         if(std::find(jacobsthal.begin(), jacobsthal.end(), i) == jacobsthal.end())
//             jacobsthal.push_back(i);
//     }
//     return jacobsthal;
// }

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



void    PmergeMe::buildChain(std::vector<std::vector<int> > matrix,std::vector<int> &mainChain,std::vector<int> &smallerChain)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        mainChain.push_back(matrix[i][1]);
        smallerChain.push_back(matrix[i][0]);
    }
}

std::vector<int>    PmergeMe::jacobsthalLinear(size_t n)
{
    std::vector<int> jacobsthal;

    if (n == 0)
        return jacobsthal;
    jacobsthal.push_back(0);
    if (n == 1)
        return jacobsthal;
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
    std::vector<int> jacobsthal = jacobsthalLinear(smallerChain.size());
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
    struct timeval startV, endV;
    gettimeofday(&startV, NULL);
    sortVector(v);
    gettimeofday(&endV, NULL);
    
    // struct timeval startD, endD;
    // gettimeofday(&startD, NULL);
    // sortMerge(d, 0, d.size() - 1);
    // gettimeofday(&endD, NULL);

    std::cout<<"After: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout<<v[i]<<" ";
    std::cout<<"\n";

    double timeV = ((endV.tv_sec  - startV.tv_sec) * 1e6 + (endV.tv_usec - startV.tv_usec));
    // double timeD = ((endD.tv_sec  - startD.tv_sec) * 1e6 + (endD.tv_usec - startD.tv_usec));
    std::cout<< std::fixed << std::setprecision(5);
    std::cout<<"Time to process a range of "<<ac - 1<<" elements with std::vector : "<< timeV <<" us"<<std::endl;
    // std::cout<<"Time to process a range of "<<ac - 1<<" elements with std::deque : "<< timeD <<" us"<<std::endl;

}
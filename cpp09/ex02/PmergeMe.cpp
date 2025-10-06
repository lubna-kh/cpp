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

bool checkArgs(char **av)
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
    return false;
}

template <typename T>
void    PmergeMe::merge(T &container, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T L(n1);
    T R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = container[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = container[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            container[k] = L[i];
            i++;
        }
        else
        {
            container[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        container[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        container[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void    PmergeMe::sortMerge(T &container, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        sortMerge(container, left, mid);
        sortMerge(container, mid + 1, right);
        merge(container, left, mid, right);
    }
}

void PmergeMe::start(int ac, char **av)
{
    if(checkArgs(av))
        return ;
    for (size_t i = 1; i < (size_t)ac; i++)
    {
        int num = atoi(av[i]);
        v.push_back(num);
        d.push_back(num);
    }
    std::cout<<"Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout<<v[i]<<" ";
    std::cout<<"\n";
    //sorting part to be added here
    struct timeval startV, endV;
    gettimeofday(&startV, NULL);
    sortMerge(v, 0, v.size() - 1);
    gettimeofday(&endV, NULL);
    
    struct timeval startD, endD;
    gettimeofday(&startD, NULL);
    sortMerge(d, 0, d.size() - 1);
    gettimeofday(&endD, NULL);

    std::cout<<"After: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout<<v[i]<<" ";
    std::cout<<"\n";

    double timeV = ((endV.tv_sec  - startV.tv_sec) * 1e6 + (endV.tv_usec - startV.tv_usec));
    double timeD = ((endD.tv_sec  - startD.tv_sec) * 1e6 + (endD.tv_usec - startD.tv_usec));
    std::cout<< std::fixed << std::setprecision(5);
    std::cout<<"Time to process a range of "<<ac - 1<<" elements with std::vector : "<< timeV <<" us"<<std::endl;
    std::cout<<"Time to process a range of "<<ac - 1<<" elements with std::deque : "<< timeD <<" us"<<std::endl;

}
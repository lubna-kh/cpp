// #include "PmergeMe.hpp"
// template <typename T>
// void    PmergeMe::merge(T &container, int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     T L(n1);
//     T R(n2);

//     for (int i = 0; i < n1; i++)
//         L[i] = container[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = container[mid + 1 + j];

//     int i = 0;
//     int j = 0;
//     int k = left;

//     while (i < n1 && j < n2)
//     {
//         if (L[i] <= R[j])
//         {
//             container[k] = L[i];
//             i++;
//         }
//         else
//         {
//             container[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1)
//     {
//         container[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2)
//     {
//         container[k] = R[j];
//         j++;
//         k++;
//     }
// }

// template <typename T>
// void    PmergeMe::sortMerge(T &container, int left, int right)
// {
//     if (left < right)
//     {
//         int mid = left + (right - left) / 2;
//         sortMerge(container, left, mid);
//         sortMerge(container, mid + 1, right);
//         merge(container, left, mid, right);
//     }
// }
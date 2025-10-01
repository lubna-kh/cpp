#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    for (int i = 1; i <= 5; ++i)
        mstack.push(i);

    //Forward iteration (non-const)
    std::cout << "Forward iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    //Forward iteration (const object)
    const MutantStack<int> cmstack(mstack);
    std::cout << "Const forward iteration:" << std::endl;
    for (MutantStack<int>::const_iterator cit = cmstack.cbegin(); cit != cmstack.cend(); ++cit)
        std::cout << *cit << " ";
    std::cout << std::endl;

    //Reverse iteration (non-const)
    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    //Reverse iteration (const object)
    std::cout << "Const reverse iteration:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = cmstack.crbegin(); crit != cmstack.crend(); ++crit)
        std::cout << *crit << " ";
    std::cout << std::endl;

    return 0;
}


// int main()
// {
//     MutantStack<int> mstack;

//     for (int i = 1; i <= 5; i++)
//         mstack.push(i);

//     std::cout << "Normal iteration (begin -> end):" << std::endl;
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     std::cout << "Const iteration (cbegin -> cend):" << std::endl;
//     for (MutantStack<int>::const_iterator it = mstack.cbegin(); it != mstack.cend(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     std::cout << "Reverse iteration (rbegin -> rend):" << std::endl;
//     for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     std::cout << "Const reverse iteration (crbegin -> crend):" << std::endl;
//     for (MutantStack<int>::const_reverse_iterator it = mstack.crbegin(); it != mstack.crend(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     // Show stack operations still work
//     std::cout << "Top element: " << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << "After pop, new top: " << mstack.top() << std::endl;
//     std::cout << "Stack size: " << mstack.size() << std::endl;

    
//     return 0;
// }






// int main()
// {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }


//using list
// #include <list>
// int main()
// {
//     std::list<int> mstack;

//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl;
//     mstack.remove(mstack.back());
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::cout << "---------------------" << std::endl;
//     std::list<int> s(mstack);
//     return 0;
// }
#include <iostream>
#include<list>
#include <algorithm>
using namespace std;
int main()
{
    list<int> l = {3, 2};

    {
        // Inserting an element at the end
        l.push_back(5);
    
        // Inserting an element at the beginning
        l.push_front(1);
    
        // Inserting an element at a specific position
        auto it = l.begin();
        advance(it, 2);
        l.insert(it, 4);
        
        for (auto i : l) 
            cout << i << " ";
    }
    std::cout<<"\n---------------------------------------------------\n";

    {

        // Accessing first and last elements
        cout << l.front() << endl;
        cout << l.back() << endl;
        
        // Access third element
        cout << *next(l.begin(), 2);
    
        l.front() = 11;
        
        // Move iterator to the second element
        auto it = l.begin();
        advance(it, 2);
        
        // Update the value using iterator
        *it = 10;
        
        for (auto i : l) 
            cout << i << " ";
    }

    std::cout<<"\n---------------------------------------------------\n";
    {
        auto it = find(l.begin(), l.end(), 4);
        
        if (it != l.end()) cout << *it;
        else cout << "Element Not Found!";
    
        std::cout<<"\n---------------------------------------------------\n";
        for (auto it = l.begin(); it != l.end(); ++it) 
            cout << *it << " ";
    }
    
    std::cout<<"\n---------------------------------------------------\n";
    {
        l.pop_back();
    
        // Deleting first element
        l.pop_front();
        
        // Deleting third element
        auto it = l.begin();
        advance(it, 2);
        l.erase(it);
    
        for (auto i : l) 
            cout << i << " ";
    }
    std::cout<<"\n---------------------------------------------------\n";
    {
        cout << "The list in reverse order: "; 
        for (auto it = l.rbegin(); it != l.rend(); ++it) 
            cout << *it << " "; 
    }
    return 0;
}
/*Stack container follows LIFO (Last In First Out) order of insertion
and deletion. It means that most recently inserted element is
removed first and the first inserted element will be removed last.
This is done by inserting and deleting elements at only one end of
the stack which is generally called the top of the stack.

* std::stack is not a container itself, it is an adaptor.
It uses another container underneath (like deque or vector) to actually store elements.
By default, it uses deque.


* Protected member c in stack:
Internally, std::stack has a protected member called c.
c is the actual container that holds the data.
Since it is protected, classes that inherit from std::stack can access it.

*/

#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    st.push(10);
    st.push(5);
    
    // Accessing top element
    cout << "Top element: " << st.top() << endl;
    
    // Popping an element
    st.pop();
    cout << "Top element after pop: " << st.top() << endl;
    std::cout<<"---------------------------------------------------\n";
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Accessing the top element
    cout << st.top()<<endl;
    std::cout<<"---------------------------------------------------\n";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    std::cout<<"\n---------------------------------------------------\n";
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    std::cout<<"---------------------------------------------------\n";

    return 0;
}


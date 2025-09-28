#include <deque>
#include <iostream>
using namespace std;

int main()
{

    deque<int> d1;

    deque<int> d2 = {10, 20, 30, 40};
    for (int val : d2) {
        cout << val << " ";
    }
    cout << endl;

    d2.push_front(30);
    d2.push_front(20);
    d2.push_front(10);
    d2.push_back(10);
    d2.push_back(20);
    d2.push_back(30);
    
    
    // Displaying elements
    cout << "Elements in deque (added using push_back/front): ";
    for (int val : d2) {
        cout << val << " ";
    }
    cout << endl;

    d2.pop_back();
    d2.pop_front();
    cout << "Deque after pop_back()/pop_front(): ";
    for (int val : d2) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

/*
 ______________________________________________________________________________________
|Feature    |             Queue           |     Deque(Double-Ended Queue)              |
|___________|_____________________________|____________________________________________|
|Definition |A linear data structure that |A generalized version of queue that         |
|           |follows FIFO (First-in-First-|allows insertion and deletion from          |
|           |Out).                        |both ends.                                  |
|___________|_____________________________|____________________________________________|
|Operations |Enqueue (add to rear) Dequeue|(remove from front)                         |
| Allowed   |                             |Insert Front, Insert Rear                   |
|           |                             |Delete Front, Delete Rear                   |
|___________|_____________________________|____________________________________________|
|           |Restricted: insertion at rear|More flexible: insertions and               |
|Access     | and deletion at front only. |deletions at both front and rear.           |
|___________|_____________________________|____________________________________________|
|           |When you need strict FIFO    |When you need both FIFO and LIFO            |
|Use Case   |ordering (e.g., task         |behavior (e.g., sliding window              |
|           |scheduling).                 |problems, palindrome checking).             |
|___________|_____________________________|____________________________________________|
|           |Simpler, but limited in      |Slightly more complex, but more             |
|Efficiency |functionality.               |powerful                                    |
|___________|_____________________________|____________________________________________|
|Types      | Simple Queue, Circular Queue|Input-Restricted Deque (insert rear only)   |
|           |     Priority Queue          |Output-Restricted Deque (delete front only) |
|___________|_____________________________|____________________________________________|

*/
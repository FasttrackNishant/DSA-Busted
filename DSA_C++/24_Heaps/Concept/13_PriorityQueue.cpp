#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // ================================
    // MAX HEAP (by default in C++)
    // ================================
    
    priority_queue<int> pq; // This creates a max heap (highest value at top)

    // Inserting elements
    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(5);

    // The top() will give the maximum element
    cout << "Top element in Max Heap: " << pq.top() << endl; // Output: 5

    // Remove the top element (5)
    pq.pop();

    // Next top element
    cout << "Top element after pop: " << pq.top() << endl; // Output: 4

    // ================================
    // MIN HEAP
    // ================================

    // Syntax: priority_queue<type, vector<type>, greater<type>>
    priority_queue<int, vector<int>, greater<int>> minHeap; // This creates a min heap (lowest value at top)

    // Inserting elements
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(3);
    minHeap.push(5);

    // The top() will give the minimum element
    cout << "Top element in Min Heap: " << minHeap.top() << endl; // Output: 2

    // Remove the top element (2)
    minHeap.pop();

    // Next top element
    cout << "Top element after pop: " << minHeap.top() << endl; // Output: 3

    return 0;
}
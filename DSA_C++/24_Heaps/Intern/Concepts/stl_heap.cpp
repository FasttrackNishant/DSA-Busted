#include <iostream>
#include <queue>

using namespace std;
int main()
{

    cout << "Using priority queue here " << endl;

    // ye ek max heap hota hain
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "element at the top is " << pq.top() << endl;

    pq.pop();
    cout << pq.top() << endl;

    cout << "size :-" << pq.size() << endl;

    cout << "pq is empty or not :-" << pq.empty() << endl;


    // agar min heap bana hian

    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"element at the top "<<minheap.top()<<endl;
    return 0;
}
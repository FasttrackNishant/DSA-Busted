#include <iostream>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data,Node* next)
    {
        data = data,
        next =next;
    }
};


int main() {
    // int x= 20;
    // int* y= &x;
    // int arr[20];
    // cout<<y<<endl;

    Node x = Node(2,nullptr);
    Node* y = &x;

    Node *z = new Node(2,nullptr);

    return 0;
}
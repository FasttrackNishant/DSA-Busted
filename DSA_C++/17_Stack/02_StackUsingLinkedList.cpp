#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class MyStack
{
public:
    Node *top;

    MyStack()
    {
        top = nullptr;
    }

    void push(int data)
    {
        Node * temp = new Node(data);
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        Node * nodeToDelete = top;

        if(top->next != nullptr)
        {
            top = top->next;
        }

        delete nodeToDelete;
    }
};

int main()
{

    return 0;
}
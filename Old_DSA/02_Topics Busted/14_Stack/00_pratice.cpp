#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        this->size = size;
    }

    void push(int element)

    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop()
    {
    }
    int peek()
    {
    }

    bool isEmpty()
    {
    }
};
int main()
{
    int a;
    cout << endl;
    return 0;
}
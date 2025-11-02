#include <iostream>
#include <stack>
using namespace std;

class Stack
{

public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
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
            cout << "stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack empty" << endl;
        }
    }

    int peek()
    {
        if (top >= 0 && top < size)
            return arr[top];
        else
        {
            cout << "stack is empty" << endl;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack s1(5);

    s1.push(34);
    s1.push(50);
    s1.push(67);

    cout << s1.peek();
    for (int i = 0; i < s1.size; i++)
    {
        cout<<arr[i];
    }
    
}

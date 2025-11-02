#include <iostream>
using namespace std;

class Stack
{

    // properties

public:
    int *arr;
    int top;
    int size;

    // behaviour

    Stack(int size)
    {
        this->size = size;
        arr = new int(size);
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
            cout << "stack overflow " << endl;
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
            cout << " Stack underflow " << endl;
        }
    }

    int peek()

    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty " << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
};
int main()
{

    Stack s(4);

    s.push(20);
    s.push(40);
    s.push(48);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;

    cout<<"Stack is empty or not "<<s.isEmpty()<<endl;

    return 0;
}
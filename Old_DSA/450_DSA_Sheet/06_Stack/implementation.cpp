#include <bits/stdc++.h>
using namespace std;
// =

class Stack
{
private:
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {

            return arr[top];
        }
    }

    int getSize()
    {

        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
            return 0;
    }
};

int main()
{
    Stack s(5);
    s.push(34);
    s.push(50);
    s.push(60);
    s.push(12);
    s.push(2);

    s.pop();
    cout << s.getTop();

    return 0;
}
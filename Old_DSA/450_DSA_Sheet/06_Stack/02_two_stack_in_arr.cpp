#include <bits/stdc++.h>
using namespace std;
// =
class Stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size)

    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    // functions

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            // space not available
            cout << "OVERFLOW int stack 1" << endl;
        }
        else
        {
            // space available
            top1++;
            arr[top1] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "no item present" << endl;
        }
        else
        {
            arr[top1] = 0;
            top1--;
        }
    }
    void push2(int data)
    {
        cout << "push2 " << endl;
        if (top2 - top1 == 1)
        {
            // space not avalable
            cout << "underflow in stack " << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "no item present" << endl;
        }
        else
        {
            arr[top2] = 0;
            top2--;
        }
    }

    void print()

    {
        cout << endl;
        cout << "top1" << top1<<endl;
        cout << "top2" << top2<<endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
};

int main()
{
    Stack s(10);
    s.push1(10);
    s.print();
    s.push1(20);
    s.push1(40);
    s.push1(60);
    s.push1(80);
    s.push2(100);
    s.push2(120);
    s.push2(140);
    s.push2(340);
    s.push2(640);
    s.print();
    s.pop1();
    s.print();
    cout << endl;
    return 0;
}
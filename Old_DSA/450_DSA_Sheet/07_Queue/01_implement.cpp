#include <iostream>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    { // check for empty or not
        if (rear == size)
        {
            cout << "queue is full " << endl;
        }
        else
        {
            arr[front] = data;
            front++;
        }
    }

    void pop()
    {
        // check for empty
        if (front == rear)
        {
            cout << "queue is empty " << endl;
        }
        else
        {
            // this is as queue is emp
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "queue is empty " << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
            return false;
    }

    int getSize()
    {
        return rear - front;
    }
}

;

int main()
{

    Queue q(10);
    q.push(4);
    q.push(10);
    q.push(14);
    q.push(19);

    cout << q.getSize() << endl;
}
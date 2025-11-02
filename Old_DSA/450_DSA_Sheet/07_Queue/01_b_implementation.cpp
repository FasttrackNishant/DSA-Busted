#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int qfront;
    int rear;
    int size;

    // yaha agar input mein size de rahe hai to thik  hain nahi toh hum hi de
    // denge

    Queue()
    {
        size = 100000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void push(int arr[], int data)
    {
        if (rear == size)
        {
            cout << "Queue is full " << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop(int arr[])
    {
        if (qfront == rear)
            cout << "queue is empty " << endl;

        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            // this is imp condtikn nahi toh queue waste ho jayegi
            if (qfront == rear)

            {
                qfront = 0;
                rear = 0;
            }
        }
    }
    int qfront(int arr[])
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }

    bool isEmpty()
    {
        if (qfront == rear)
            return 1;

        else
            return 0;
    }
}

;

int main()
{

    Queue q1;

    // q1.push(arr, 34);
    // cout << q1.isEmpty();
}
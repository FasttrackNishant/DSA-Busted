#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor
    Queue(int s = 1000001)
    {
        capacity = s;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue()
    {
        delete[] arr;
    }

    // Check if queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Enqueue operation
    bool enqueue(int val)
    {
        // Check whether queue is full
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return false;
        }
        
        // First element
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        // Circular increment
        else if (rear == capacity - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        
        arr[rear] = val;  // Fixed: assign to arr[rear], not arr[front]
        size++;
        return true;
    }

    // Dequeue operation
    int dequeue()  // Fixed: returns the dequeued value
    {
        // Check if queue is empty
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        
        int val = arr[front];
        
        // Single element case
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        // Circular increment
        else if (front == capacity - 1)
        {
            front = 0;
        }
        // Normal case
        else
        {
            front++;
        }
        
        size--;
        return val;
    }

    // Get front element without removing
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Get current size
    int getSize()
    {
        return size;
    }

    // Display queue elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue elements: ";
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
        else
        {
            for (int i = front; i < capacity; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);  // Queue of capacity 5
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30
    
    cout << "Front element: " << q.getFront() << endl;  // 10
    cout << "Rear element: " << q.getRear() << endl;    // 30
    
    q.dequeue();
    q.display();  // Output: 20 30
    
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();  // Output: 20 30 40 50 60
    
    q.enqueue(70);  // Should show "Queue is full"
    
    return 0;
}
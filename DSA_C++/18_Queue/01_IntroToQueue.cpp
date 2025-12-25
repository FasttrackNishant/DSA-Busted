// implement using array 

#include <iostream>
using namespace std;


class Queue{

    int * arr;
    int front ;
    int rear;
    int size ;

    Queue()
    {
        size = 100001;
        arr = new int [size];
        front = 0 ;
        rear = 0;
    }

    bool isEmpty()
    {
       
    }

    void enqueue(int data)
    {
      if(rear == size)
        {
            cout << " Full ";
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }   

    int deque(){
        if(front == rear)
        {
            cout<<"Queue is empty";
        }
        else{
            arr[front] = -1;
            front++;
            
            if(front == rear)
            {
                front = 0 ;
                rear = 0;
            }
        }
    }

    int front()
    { 
        if(front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        return front==rear;
    }
    
    
};

int main() {
    
    return 0;
}
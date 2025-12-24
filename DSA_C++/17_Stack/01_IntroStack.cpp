#include <iostream>
#include <stack>
using namespace std;

class Stack {
    public:
        int *arr;    // Pointer to dynamic array
        int top;     // Index of top element
        int size;    // Maximum capacity
        
    // Constructor: Initialize stack with given size
    Stack(int size) {
        this->size = size;
        top = -1;    // -1 indicates empty stack
        arr = new int[size];
    }
    
    // Destructor: Free allocated memory
    ~Stack() {
        delete[] arr;
    }
    
    // Push element onto stack
    void push(int element) {
        // Check if stack has space
        if (size - top > 1) {  // Fixed: should be > 1, not > 0
            top++;
            arr[top] = element;
            cout << "Pushed: " << element << endl;
        } else {
            cout << "Stack Overflow! Cannot push " << element << endl;
        }
    }
    
    // Remove top element from stack
    void pop() {
        if (top >= 0) {  // Check if stack is not empty
            cout << "Popped: " << arr[top] << endl;
            top--;
        } else {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
        }
    }
    
    // Return top element without removing it
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;  // Return sentinel value
        }
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }
    
    // Get current number of elements in stack
    int getSize() {
        return top + 1;
    }
    
    // Display all elements in stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    // Clear all elements from stack
    void clear() {
        top = -1;
        cout << "Stack cleared!" << endl;
    }
    
    // Check if stack is full
    bool isFull() {
        return (top == size - 1);
    }
};

int main() {
    cout << "=== Custom Stack Implementation ===" << endl;
    
    // Create custom stack with capacity 5
    Stack myStack(5);
    
    // Test custom stack operations
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    cout << "Top element: " << myStack.peek() << endl;
    cout << "Stack size: " << myStack.getSize() << endl;
    
    myStack.display();
    
    myStack.pop();
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);  // This should work
    myStack.push(70);  // This might cause overflow
    
    myStack.display();
    
    // Test edge cases
    while (!myStack.isEmpty()) {
        myStack.pop();
    }
    
    myStack.pop();  // Should show underflow message
    
    cout << "\n=== STL Stack Implementation ===" << endl;
    
    // Stack using STL
    stack<int> st;
    
    st.push(34);
    st.push(56);
    st.push(78);
    
    cout << "STL Stack size: " << st.size() << endl;
    cout << "STL Stack top: " << st.top() << endl;
    
    st.pop();
    cout << "After pop, top: " << st.top() << endl;
    
    cout << "Is STL stack empty? " << (st.empty() ? "Yes" : "No") << endl;
    
    // Additional STL stack operations
    st.push(100);
    st.push(200);
    
    // Swap stacks
    stack<int> st2;
    st2.push(500);
    st2.push(600);
    
    st.swap(st2);
    cout << "\nAfter swap:" << endl;
    cout << "st top: " << st.top() << endl;
    cout << "st2 top: " << st2.top() << endl;
    
    // Emplace (construct in-place)
    stack<pair<int, string>> complexStack;
    complexStack.emplace(1, "John");  // More efficient than push + make_pair
    complexStack.emplace(2, "Alice");
    
    cout << "\nComplex stack top: (" << complexStack.top().first 
         << ", " << complexStack.top().second << ")" << endl;
    
    return 0;
}
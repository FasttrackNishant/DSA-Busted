#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Convert array to Linked List
Node* convertToLL(int arr[], int size) {
    if (size == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < size; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Print Linked List
void printLinkedList(Node* head) {
    if (head == nullptr) {
        cout << "Empty hain" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Length of Linked List
int lengthOfLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Delete at head
Node* deleteAtHead(Node* head) {
    if (head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete at tail
Node* deleteAtTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}



// Main function
int main() {
    int arr[] = {34, 2, 1, 33, 22};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Main array" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Node* head = convertToLL(arr, size);
    cout << "Converted Linked List" << endl;
    printLinkedList(head);

    cout << "Length of Linked List: " << lengthOfLinkedList(head) << endl;

    // Uncomment if needed
    // cout << "After Deleting at Head" << endl;
    // head = deleteAtHead(head);
    // printLinkedList(head);

    cout << "After Deleting at Tail" << endl;
    head = deleteAtTail(head);
    printLinkedList(head);

    return 0;
}
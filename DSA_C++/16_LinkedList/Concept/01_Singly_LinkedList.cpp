#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

// Convert array to linked list
Node* convertToLL(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Print linked list
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

// Length of linked list
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
    return head->next;
}

// Delete at tail
Node* deleteAtTail(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Delete at K position (1-indexed)
Node* deleteAtK(Node* head, int k) {
    if (head == nullptr) return head;
    if (k == 1) return head->next;

    int count = 1;
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        if (count == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    return head;
}

// Delete value = k
Node* deleteKthValue(Node* head, int k) {
    if (head == nullptr) return head;

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == k) {
            if (prev != nullptr) {
                prev->next = temp->next;
                delete temp;
            } else {
                // First node is the one to delete
                Node* newHead = temp->next;
                delete temp;
                return newHead;
            }
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// Insert at head
Node* insertAtHead(Node* head, int k) {
    return new Node(k, head);
}

// Insert at tail
Node* insertAtTail(Node* head, int value) {
    if (head == nullptr) return new Node(value);

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(value);
    return head;
}

// Insert at position (1-indexed)
Node* insertAtPosition(Node* head, int value, int position) {
    if (position == 1) return new Node(value, head);

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) return head;

    Node* newNode = new Node(value, temp->next);
    temp->next = newNode;
    return head;
}

int main() {
    int arr[] = {101, 102, 103, 104, 105};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Main array" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    Node* head = convertToLL(arr, n);
    cout << "Converted Linked List" << endl;
    printLinkedList(head);

    cout << "Length of Linked List: " << lengthOfLinkedList(head) << endl;

    // Uncomment any operation to test

    // head = deleteAtHead(head);
    // head = deleteAtTail(head);
    // head = deleteAtK(head, 3);
    // head = deleteKthValue(head, 104);
    // head = insertAtHead(head, 100);
    // head = insertAtTail(head, 999);
    head = insertAtPosition(head, 100, 2);

    cout << "Modified Linked List:" << endl;
    printLinkedList(head);

    return 0;
}
// Reverse the linked list in the iterrative way

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void printlist(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverselist(Node *&head)
{

    Node *prev = NULL;
    Node *curr = head;

    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        
    }
    return prev;
}

int main()
{

    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    Node *node3 = new Node(40);
    Node *head = node1;
    Node *tail = node1;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    printlist(head);
    reverselist(head);
    cout << head->data << endl;
    cout << tail->data << endl;

    return 0;
}
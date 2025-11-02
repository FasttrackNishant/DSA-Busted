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

Node *reverseLL(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
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
void insertatTail(Node *&tail, int d)
{

    Node *temp = new Node(d);

    tail->next = temp;
    // tail = tail->next;
    tail = temp;
}

void printll(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)

    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(45);
    Node *head = node1;
    Node *tail = node1;

    printll(head);
    insertatTail(tail, 55);
    printll(head);
    insertatTail(tail, 65);
    printll(head);
    insertatTail(tail, 80);
    printll(head);

    reverseLL(head);
    printll(tail);

    return 0;
}
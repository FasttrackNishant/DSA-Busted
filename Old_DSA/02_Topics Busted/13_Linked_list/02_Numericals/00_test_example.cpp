// reveerse ll

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

void printlist(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void reverse(Node *head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node * forward = curr ->next;
    reverse(head, forward, curr);
    curr ->next = prev;
}

Node *reverselist(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;

    reverse(head, curr, prev);
}
/*
Node * reverselist(Node *&head)
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
}*/
int main()
{
    Node *node1 = new Node(4);
    Node *head = node1;
    Node *tail = node1;
    printlist(head);
    insertAtTail(tail, 5);
    printlist(head);
    insertAtTail(tail, 6);
    printlist(head);

    reverselist(head);
    printlist(tail);

    return 0;
}
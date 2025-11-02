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

void reverse(Node *&head, Node *curr, Node *prev)
{

    // base case

    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    reverse(head , forward ,curr);
    curr ->next = prev;
}
Node *reversell(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;

    reverse(head, curr, prev);
    return head;
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

    reversell(head);
    printll(tail);

    return 0;
}
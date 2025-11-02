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
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt != position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeinsert = new Node(d);
    nodeinsert->next = temp->next;
    temp->next = nodeinsert;
}

int main()
{
    Node *node1 = new Node(30);
    Node *head = node1;
    Node *tail = node1;
    cout << "This Linked List Exercies " << endl;

    printlist(head);
    insertAtHead(head, 40);
    printlist(head);
    insertAtHead(head, 60);
    printlist(head);
    insertAtTail(tail, 90);
    printlist(head);
    insertAtPosition(head, tail, 3, 100);
    printlist(head);
    insertAtPosition(head, tail, 1, 10);
    printlist(head);
    insertAtPosition(head, tail, 7, 200);
    printlist(head);

    return 0;
}
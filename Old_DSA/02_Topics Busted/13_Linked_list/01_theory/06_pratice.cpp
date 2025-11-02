#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;

        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for the data " << val << endl;
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

void getlenght(Node *head)

{
    Node *tmep = head;
    int len = 0;
    while (tmep != NULL)
    {
        len++;
        tmep = tmep->next;
    }
    cout << "The lenght is " << len << endl;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *nodetoinsert = new Node(d);
    int cnt = 1;
    Node *temp = head;

    while (cnt < position - 1)
    {
        cnt++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deltenode(Node *head, int position)
{

    // for the head
    if (position == 2)
    {
        Node *temp = head;

        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;

        delete temp;
    }
     {
        // anything other than 1
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{

    Node *node1 = new Node(30);
    Node *head = node1;
    Node *tail = node1;

    printlist(head);
    getlenght(head);

    insertAtHead(head, 56);
    printlist(head);
    getlenght(head);

    insertAtTail(tail, 90);
    printlist(head);
    getlenght(head);

    insertAtPosition(head, tail, 2, 100);
    printlist(head);
    getlenght(head);

    deltenode(head, 2);
    printlist(head);
    getlenght(head);

    return 0;
}
#include <iostream>
using namespace std;

class Nodelist
{
public:
    int data;
    Nodelist *next;

    Nodelist(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertatHead(Nodelist *&head, int d)
{
    Nodelist *temp = new Nodelist(d);
    temp->next = head;
    head = temp;
}

void printlist(Nodelist *&head)
{

    Nodelist *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertatTail(Nodelist *&tail, int d)
{
    Nodelist *temp = new Nodelist(d);
    tail->next = temp;
    tail = tail->next;
}

void insertatposition(Nodelist *&tail, Nodelist *&head, int position, int d)
{ // starting wala case yaha ho gaya ab
    if (position == 1)
    {
        insertatHead(head, d);
        return;
    }

    Nodelist *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // ab agar hum last mein add kar rahe hain to sab sahi hain but tail update nahi hua to ab kya kare

    // inserting at last position
    if (temp->next == NULL)
    {
        insertatTail(tail, d);
        return;
    }

    // ab nayi node banate hain

    Nodelist *nodetoinsert = new Nodelist(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

int main()
{

    Nodelist *node1 = new Nodelist(56);

    Nodelist *head = node1;
    Nodelist *tail = node1;

    printlist(head);
    insertatTail(tail, 45);
    printlist(head);

    insertatTail(tail, 70);

    printlist(head);

    insertatposition(tail, head, 4, 90);
    printlist(head);

    
}
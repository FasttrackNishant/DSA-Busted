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

    // destructor
    ~Nodelist()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for the data with value " << value << endl;
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

void deletenode(Nodelist *&head, int position)
{

    if (position == 1)
    {
        // ye alaga mamla hain
        Nodelist *temp = head;
        head = head->next;

        // ab memory free karni padegi old head ki
        temp ->next = NULL;
        delete temp;
    }
    else
    {
        // anything other than 1
        Nodelist *current = head;
        Nodelist *previous = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            previous = current;
            current = current->next;
            cnt++;
        }

        previous->next = current->next;
        current ->next  = NULL;
        delete current;
    }
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

    deletenode(head, 4 );
    printlist(head);
}
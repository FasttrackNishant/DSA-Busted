#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    // consturctor

    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~node()

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

void printlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlength(node *head)

{
    int lenght = 0;
    node *temp = head;
    while (temp != NULL)
    {
        lenght++;
        temp = temp->next;
    }
    return lenght;
}
void insertathead(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertatTail(node *&tail, node *&head, int d)
{

    if (tail == NULL)
    {//ye wali case jab tail null ho tabhi use hogi

        node *temp = new node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        //this is default equation

        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertatposition(node *&tail, node *&head, int position, int d)
{
    if (position == 1)
    {
        insertathead(head, tail, d);
        return;
    }

    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {

        insertatTail(tail, head, d);
        return;
    }

    // middl mein kar nahian to

    node *nodetoinsert = new node(d);

    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deletenode(node *&head, int position)
{

    if (position == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;

        // ab memory free karni padegi old head ki
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // anything other than 1
        node *current = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = current;
            current = current->next;
            cnt++;
        }

        current->prev = NULL;
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

int main()
{
    // node *node1 = new node(30);
    // node *head = node1;
    // node *tail = node1;

    // agar ye upar ke ek line delte kardi and bakiko NULL se initialize kar diya toh kya hoga ab hoga yesa

    node *head = NULL;
    node *tail = NULL;

    printlist(head);
    cout << getlength(head) << endl;

    insertathead(head, tail, 40);
    printlist(head);

    insertathead(head, tail, 50);
    printlist(head);

    insertathead(head, tail, 60);
    printlist(head);

    insertatTail(tail, head, 90);
    printlist(head);
    cout << getlength(head) << endl;

    insertatposition(tail, head, 2, 100);
    printlist(head);
    insertatposition(tail, head, 6, 200);
    printlist(head);

    deletenode(head, 5);
    printlist(head);
    return 0;
}
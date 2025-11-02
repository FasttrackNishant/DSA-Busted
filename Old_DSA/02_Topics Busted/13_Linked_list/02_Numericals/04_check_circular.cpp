#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertatnode(node *&tail, int element, int d)
{

    // assuming that the element is present in the list

    // empty list
    if (tail == NULL)
    {

        node *newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        // for non empty list i.e element is present in the list

        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // ab bahar aa gaye means element found ho gaya ab woh represent kar raha hain element wala node

        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void printlist(node *&tail)
{
    node *temp = tail;
    //    cout << tail->data << " ";

    // while (tail->next != temp)
    // {
    //     cout << temp->data << " ";
    //     tail = tail->next;
    // }

    // cout << " ";

    // but agar node single hain to hum is logic ke hisab se print inahi kar sakte

    // ek aur way hain do while  loop

    // agar empty list hain to kya print karoge

    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deltenode(node *&tail, int value)
{
    // empty list

    if (tail == NULL)
    {
        cout << "list is empty " << endl;
        return;
    }

    else
    {
        // non-empty wala part

        // assuming that value is present

        node *prev = tail;
        node *curr = prev->next;

        while (curr->data != value)
        {

            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 node present only

        if (curr == prev)
        {
            tail = NULL;
        }

        //>= 2 node presents
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool checkcircular(node *&head)
{
    // empty list case
    if (head == NULL)
    {
        return true;
    }

    node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

int main()
{

    node *tail = NULL;

    insertatnode(tail, 5, 20);

    printlist(tail);
    insertatnode(tail, 20, 25);

    printlist(tail);
    // insertatnode(tail, 25, 30);
    // printlist(tail);
    // insertatnode(tail, 20, 60);
    // printlist(tail);
    // insertatnode(tail, 25, 45);
    // printlist(tail);
    // insertatnode(tail, 60, 88);
    if (checkcircular(tail))
    {
        cout << "linked list is circular in nature " << endl;
    }
    else
    {
        cout << "linked list is not circular ";
    }
}
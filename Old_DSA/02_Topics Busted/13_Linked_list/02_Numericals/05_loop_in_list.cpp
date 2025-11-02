#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertatNode(Node *&tail, int element, int d)
{

    // assuming that the element is present in the list

    // empty list
    if (tail == NULL)
    {

        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // for non empty list i.e element is present in the list

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // ab bahar aa gaye means element found ho gaya ab woh represent kar raha hain element wala Node

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void printlist(Node *&tail)
{
    Node *temp = tail;
    //    cout << tail->data << " ";

    // while (tail->next != temp)
    // {
    //     cout << temp->data << " ";
    //     tail = tail->next;
    // }

    // cout << " ";

    // but agar Node single hain to hum is logic ke hisab se print inahi kar sakte

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

void delteNode(Node *&tail, int value)
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

        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {

            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node present only

        if (curr == prev)
        {
            tail = NULL;
        }

        //>= 2 Node presents
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool checkcircular(Node *&head)
{
    // empty list case
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;

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

bool checkloop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    // ab map banate hain

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {
        // check karo pehle se hi true mark hain ya nahi
        if (visited[temp] == true)
        {
            // cycle is present
            // konse se node pre hain
            cout << "present on the node " << temp->data << endl;
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floydDetect(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (slow == fast)
            cout << "meetup at " << slow->data << endl;
        return slow;
    }

    return NULL;
}

Node *getstartingnode(Node *head)
{
    if (head == NULL)
        return NULL;


    //ab point of intersection chhahiye

    Node *intersection = floydDetect(head);
    Node * slow = head;
    
    while (slow !=intersection)
    {
        slow = slow ->next;
        intersection = intersection ->next;
             
    }

    return slow;
    
}

int main()
{

    Node *tail = NULL;

    insertatNode(tail, 5, 20);

    insertatNode(tail, 20, 25);
    insertatNode(tail, 25, 30);
    // printlist(tail);
    // insertatNode(tail, 20, 60);
    // printlist(tail);
    // insertatNode(tail, 25, 45);
    // printlist(tail);
    // insertatNode(tail, 60, 88);
    printlist(tail);
    if (checkcircular(tail))
    {
        cout << "linked list is circular in nature " << endl;
    }
    else
    {
        cout << "linked list is not circular ";
    }
    cout << checkloop(tail);
    if (floydDetect(tail) != NULL)
    {
        cout << "loop is present " << endl;
    }
    else
    {
        cout << "loop is not present ";
    }
    cout << endl;
}
#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertatHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

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

void insertatTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
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
        {
            cout << "meetup at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

Node *getstartingNode(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = floydDetect(head);

    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node *removecycle(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *startofloop = getstartingNode(head);

    Node *temp = startofloop;

    while (temp ->next != startofloop)
    {
        temp = temp ->next; 
    }
    temp ->next = NULL;
}
int main()
{

    Node *node1 = new Node(56);

    Node *head = node1;
    Node *tail = node1;
    insertatTail(tail, 45);
    insertatTail(tail, 70);
    insertatTail(tail, 90);
    insertatTail(tail, 100);

    printlist(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    tail->next = head->next->next;
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    cout << "is circular :-" << checkloop(head) << endl;
    // cout << "contain loop  :-" << checkloop(head) << endl;
    removecycle(head);
    if (floydDetect(head) != NULL)
    {
        cout << "loop is present " << endl;
    }
    else
    {
        cout << "loop is not present " << endl;
    }
    cout << "loop starts at the node " << getstartingNode(head)->data << endl;
}
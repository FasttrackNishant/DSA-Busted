#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * prev;
        Node * next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printList(Node * head)
{
    Node * temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}

void insertAtHead(Node * &head, Node * &tail , int val)
{
    if(!head)
    {
        Node * nodeToInsert =new Node(val);
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    else
    {
        Node * nodeToInsert = new Node(val);
        nodeToInsert->next = head;
        head->prev = nodeToInsert;
        head = nodeToInsert;
    }
}

void insertAtTail(Node * &head , Node * & tail , int val)
{
    if(!head)
    {
        Node * newNode = new Node(val);
        tail = newNode;
        head = newNode;
    }
    else
    {
        Node * temp = head;
        while(temp->next)
        {
            temp = temp->next;
        }

        Node * newNode = new Node(val);
        tail->next = newNode;
        newNode ->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node * & head , Node * &tail, int pos , int val)
{
    if(!head)
    {
        Node * nodeToInsert = new Node(val);
        head = nodeToInsert;
        tail = nodeToInsert;
    }
    else
    {
        int cnt = 1 ;
        Node * temp = head;
        while(cnt < pos-1)
        {
            temp = temp->next;
            cnt++;
        }

        Node * nodeToInsert = new Node(val);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;

    }
}

void deleteNode(Node * & head , Node * &tail, int val , int pos)
{
 
    if(pos == 1)
    {
        Node * temp = head->next;
        head->next = nullptr;
        temp->prev = nullptr;
        delete head;
        head = temp;
    }
    else{
        Node * curr = head;
        Node * prev = nullptr;

        int cnt = 1;
        while(cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = nullptr;
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
}


int main() {

    Node * node1 = new Node(20);
    Node * temp = nullptr;

    Node * head = nullptr;
    Node * tail = nullptr;
    
    insertAtHead(head,tail,30);

    insertAtHead(head,tail,20);

    insertAtTail(head,tail,40);

    insertAtTail(head,tail,60);

    insertAtPosition(head, tail , 2 , 90);

    printList(head);
    deleteNode(head, tail , 11 , 2);

    printList(head);


    
    return 0;
}
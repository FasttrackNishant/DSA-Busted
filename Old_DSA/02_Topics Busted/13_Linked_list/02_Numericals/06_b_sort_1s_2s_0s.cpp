#include <iostream>
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

void insertAtTail(Node *&tail, Node *curr)
{

    tail->next = curr;
    tail = curr;
}

// hume yaha replace nahi karna hain

Node *sortList(Node *head)
{

    // 3 dummy node banate hain

    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);

    Node *zerotail = zerohead;
    Node *onetail = onetail;
    Node *twotail = twotail;

    Node *curr = head;

    while (curr != NULL)
    {
        // ab yaha linkage lagate hain agar o hain to o ki list mein jao with the help of populate function

        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zerotail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(onetail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twotail, curr);
        }

        curr = curr->next;
    }

    // merge kardo in sublists ko

    if (onehead->next != NULL) // i.e ye non empty hain
    {
        zerotail->next = onehead->next;
    }
    else

    {
        zerotail->next = twohead->next;
    }

    onetail->next = twohead->next;

    twotail->next = NULL;

    // ab ye hone ke abad un list ki need nahi hai to unhe delete kardo and head hoga woh zerohead ->next mein leke aao

    head = zerohead->next;

    // delte dummy nodes

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;  
}

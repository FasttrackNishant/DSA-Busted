#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;


//constructor used in this case
    node (int data)
    {
        this -> data = data;
        this -> next = NULL; 
    }
};

void insertatHead(node* &head)

int main()
{
    // created node in this way
    node *node1 = new node(10);

    // read data in ll
    cout << node1->data << endl;
    // read ptr in ll
    cout << node1->next << endl;
    cout << endl;
    return 0;
}
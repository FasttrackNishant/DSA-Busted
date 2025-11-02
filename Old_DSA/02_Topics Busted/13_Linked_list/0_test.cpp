#include <iostream>
using namespace std;

class nodelist
{
public:
    int data;
    nodelist *next;

nodelist(int data)
{
    this -> data = data;
    this -> next = NULL;
}

};

int main()
{
    nodelist *node1 = new nodelist(25);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    return 0;
}
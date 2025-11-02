#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * left ;
        Node * right ; 

    Node(int d)
    {
        this->left = NULL;
        this-> right = NULL ;
        this->data = d;
    }
};



int main() {

    Node * root = new Node(34);
    cout<<"Is sum Tree"<< isSumTree(root);

    return 0;
}
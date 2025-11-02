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

    cout << "Hello World" << endl;

    return 0;
}
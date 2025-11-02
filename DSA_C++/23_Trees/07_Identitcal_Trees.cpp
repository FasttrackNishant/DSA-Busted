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

bool isIdentical(Node * root1 , Node * root2)
{
    if(root1== NULL && root2 ==NULL)
        return true;
    
    if(root1==NULL && root2 !=NULL)
        return false;

    if(root1 !=NULL && root2==NULL)
    {
        return false;
    }

    bool leftAns  = isIdentical(root1->left , root2 -> left);
    bool rightAns = isIdentical(root1->right , root2 ->right);

    bool value = root1->data == root2->data ;

    if(leftAns && rightAns && value )
        return true
    else   
        return false;
}

int main() {
    Node * 
    cout << "Hello World" << endl;

    return 0;
}
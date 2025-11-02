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

int heightofTree(Node * root)
{
    //base case
    if(root==NULL) return 0;

    int leftAns = heightofTree(root->left);
    int rightAns = heightofTree(root->right);

    int finalAns = max(leftAns,rightAns) + 1;

    return finalAns;
}

int main() {
    
    return 0;
}
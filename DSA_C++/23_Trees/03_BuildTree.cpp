#include <iostream>
#include <queue>
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

 Node * BuildTree(Node *root)
{
    int data;
    cout<<"Enter data"<<endl;
    cin>> data;

    if(data == -1)
        return NULL;

    root = new Node(data);

    // left
    cout<<"left of"<<root->data<<endl;
    root->left = BuildTree(root->left);

    // right

    cout<<"Right of "<<root->data<<endl;
    root ->right = BuildTree(root->right);

    return root;
}

void  buildTreeFromLevelOrder(Node * &root)
{
    queue<Node *> q;
    cout<<"Enter data "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    q.push(root);

    while (!q.empty())
    {
        Node * temp = q.front();
        q.pop();

        cout<<"Enter value for temp left"<<temp->data<<endl;
        int leftData ;
        cin>> leftData;

        if(leftData !=-1)
            temp ->left = new Node(leftData);
            q.push(temp->left);

        cout<<"Enter the data for Right Node"<<temp->data <<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1 )
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    




    



}

int main() {

    Node *root = NULL;
    // root = BuildTree(root);
     buildTreeFromLevelOrder(root);

}
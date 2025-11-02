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

Node * buildTree(Node * root)
{
    cout<<"Enter data "<<endl;
    int data;
    cin>>data ;
    root = new Node(data);

    if(data == -1)
        return NULL;

    //left ki call

    cout<<"left hain "<<root->data<<endl;
    root->left = buildTree(root->left);


    // right ki call
    cout<<"right hain "<<root->data<<endl;
    root->right  = buildTree(root->right);
 
    //return
    return root; 
}


//for printing the tree

void levelOrderTraversal(Node * root)
{
    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node * temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}

void levelOrderTraversalWithLine(Node * root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout<<"yaha new "<<endl;
    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        
        
        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(Node * root){
      
}

void inorder(Node * root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preOrder(Node * root)
{
    if(!root)
        return ;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node * root)
{
    if (!root)
        return;
    postOrder(root->right);
    postOrder(root->left);
    cout << root->data << " ";
}

Node * buildTreeFromLevelOrder(Node * root)
{
    queue<Node *> q;
    q.push(root);
}


int main() {
    

    Node * root =NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    cout<<"level order with line"<<endl;
    levelOrderTraversalWithLine(root);
    cout<<"Reverse level order"<<endl;
    reverseLevelOrderTraversal(root);
    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<"Pre Order"<<endl;
    preOrder(root);
    return 0;
}


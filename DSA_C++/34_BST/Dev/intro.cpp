#include <iostream>
#include <queue>
using namespace std;

class Node 
{
    public :
        int data;
        Node * left ;
        Node * right;

    Node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void printInorder(Node *root)
{
    if(!root) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printLevelOrder(Node * root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        
        if(temp == nullptr)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node * insertIntoBST(Node * root , int data)
{
    if(!root)
    {
        root = new Node(data);
        return root;
    }

    if(data < root->data)
    {
        //left ki call 
      root ->left =   insertIntoBST(root->left , data);

    }
    else 
    {
        // right ki call
        root -> right = insertIntoBST(root->right,data);
    }
    return root;

}

void takeInput(Node *&root)
{   int data;
    cin>>data;
    while(data != -1)
    {
        root = insertIntoBST(root , data);
        cin>>data;

    }
}

Node * searchInBSTRecursive(Node * root , int val)
{
    if(!root || root->data ==val) return root;

    if(root->data < val)
    {
        return searchInBSTRecursive(root->right,val);
    }
    else
    {
        return searchInBSTRecursive(root->left,val);
    }
}

Node * searchInBSTIterative(Node * root , int val)
{
    Node * temp = root;
    while(temp !=nullptr || temp->data == val)
    {
        if(temp->data < val)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp ->left;
        }
    }

    return temp;
}

int minimumValofBST(Node * root)
{
    Node * temp = root;
    while(temp != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maximumValofBST(Node * root)
{
    Node * temp = root;
    while(temp != nullptr)
    {
        temp = temp -> right;
    }
    return temp->data;
}



int main() {

    Node * root = nullptr;

    cout<<"Taking input for the tree"<<endl;
    takeInput(root);

    printLevelOrder(root);

    printInorder(root);
    
    return 0;
}
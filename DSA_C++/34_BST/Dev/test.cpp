//insert into bst
#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;
		
	Node(int d)
	{
		 this->data = d;
		 this->left = nullptr;
		 this->right = nullptr;
	}
};

void levelOrderTraversal(Node * root)
{
    if(!root) return ;

    queue<Node * > q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();

        if(!temp)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->data<<" "<<endl;

            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node * insertIntoBST(Node * root , int data)
{
    if(!root) return new Node(data);

    if(data < root->data)
    {
       root->left = insertIntoBST(root->left,data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node * &root)
{
		int data;
		cout<<"Input data for the tree"<<endl;
		
		cin>>data;
	
		while(data !=-1)
		{
			root = insertIntoBST(root,data);
			
			cin>>data;
		
		}
}

int main()
{
    Node * root = nullptr;

    takeInput(root);

    levelOrderTraversal(root);
    
}
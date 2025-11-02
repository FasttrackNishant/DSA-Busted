#include <iostream>
using namespace std;

class Node
{
    public:
    Node * left ;
    Node * right;
    int data ;

    Node(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

Node * BuildTree(Node * root)
{
    cout<<"Enter the root data"<<endl;
    int data;
    cin>>data;
    
    if(data ==-1)
        return NULL;
    root = new Node(data);

    cout<<"left main"<<root->data<<endl;
   root->left =  BuildTree(root->left);

    cout<<"Right of "<<root->data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

//inorder by iteration

void inOrder(Node * root)
{
    stack<Node*> st ;
    Node * current = root;

    while(current !=nullptr )
    {
        while (current !=nullptr)
        {  
            cout<<"Curr is"<<current->data<<" "<<endl;
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout<<current->data <<" ";
        current = current->right;
    }
}

int main() {

    Node * root = NULL;
    root = BuildTree(root);
    inOrder(root);
    return 0;
}
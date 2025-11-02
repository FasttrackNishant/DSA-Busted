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

pair<bool,int> isBalancedFast(Node * root)
{
    if(root==NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int>  leftAns= isBalancedFast(root->left);

    pair<bool,int> rightAns = isBalancedFast(root->right);

    bool diff = abs(leftAns.second- rightAns.second) <=1;

    pair<bool,int> ans;
    ans.second = max(leftAns.second, rightAns.second) + 1;
    if(leftAns.first && rightAns.first && diff)
    {
        ans.first = true;
    }
    else 
        ans.first = false;
  

}


/* dekh issue ho gayi hain o->n2 mein nahi yaar galat hain */

bool isBalanced(Node * root)
{
    if(root==NULL) return 1;

    bool left = isBalanced(root->left);

    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left)- height(root->right)) < = 1

    if(left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() {

    cout << "Hello World" << endl;

    return 0;
}

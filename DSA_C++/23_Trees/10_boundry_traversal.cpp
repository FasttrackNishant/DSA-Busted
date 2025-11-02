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

vector<int> traverseLeftBoundry(Node * root , vector<int>& ans)
{
    if(root==nullptr || ( root->left ==nullptr && root->right == nullptr ) )
        return ans;

    ans.push_back(root->data);

    if(root->left)
        traverseLeftBoundry(root->left,ans);
    
    if(root->right)
        traverseRightBoundry(root->right,ans);
    
    
}

vector<int> traverseLeafBoundry(Node * root , vector<int>& ans)
{
    if (root == nullptr)
        return ans;

    if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->data);
            return;
        }

        traverseLeafBoundry(root->left,ans);
        traverseLeafBoundry(root->right, ans);
}

vector<int> traverseRightBoundry(Node * root , vector<int>& ans)
{
    if(root==nullptr || ( root->left ==nullptr && root->right == nullptr ) )
        return ans;

    if (root->left)
        traverseRightBoundry(root->left, ans);

    if (root->right)
        traverseRightBoundry(root->right, ans);

    ans.push_back(root->data);
}

vector<int> solve(Node * root)
{
    vector<int> ans;
    // base handle
    if(root==nullptr)
        return ans;

    ans.push_back(root->data);
    
    traverseLeftBoundry(root->left,ans);

    traverseLeafBoundry(root->left,ans);
    
    traverseLeafBoundry(root->right,ans);

    traverseRightBoundry(root->right,ans);

    return ans;
}


int main() {

    cout << "Hello World" << endl;

    return 0;
}
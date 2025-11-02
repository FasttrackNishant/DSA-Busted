#include <iostream>
#include <Tree.h>
using namespace std;

bool solve(Node * root , int minVal , int maxVal)
{
    if(!root) return true;

    if(root->data > minVal && root->data < maxVal)
    {
        auto leftAns = solve(root->left,root->data,maxVal);
        auto rightAns = solve(root->right, minVal, root->data);

        return leftAns && rightAns;
    }
    else {
        return false;
    }
}


bool isValidBST(Node * root)
{
    return solve(root,INT_MIN,INT_MAX);
}

int main() {
    
    return 0;
}
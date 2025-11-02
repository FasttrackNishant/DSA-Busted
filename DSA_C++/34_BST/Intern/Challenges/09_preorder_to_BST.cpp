#include <iostream>
using namespace std;

BinaryTreeNode<int> *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    // means array se bahar nikal chuke hain
    if (i >= preorder.size())
    {
        return NULL;
    }

    if (preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    Node *root = new Node(preorder[i]);

    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}

int main()
{
    int a;
    cout << endl;
    return 0;
}
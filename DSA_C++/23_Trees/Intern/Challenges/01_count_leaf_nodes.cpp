#include <iostream>
using namespace std;

// void inorder(node *root, int &count)
{
    // inorder traversal logic

    // base case
    if (root == NULL)
        return;

    inorder(root->left, count);

    // condition check karo

    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    // right ka inorder

    inorder(root->right, count);
}

int main()
{
    int a;
    cout << endl;
    return 0;
}
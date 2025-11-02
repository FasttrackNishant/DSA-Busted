#include <iostream>
#include "Tree.h"
using namespace std;

int solve(Node *root, int &i, int k)
{
    // basea case

    if (root == NULL)
        return -1;

    // L
    int left = solve(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    // N
    i++;
    if (i == k)
    {
        return root->data;
    }

    // R
    return solve(root->right, i, k);
}

int kthsmalles(Node *root, )
{
    int i = 0;  
    int ans = solve(root, i, k);
    return ans;
}
int main()
{
    int a;
    cout << endl;
    return 0;
}
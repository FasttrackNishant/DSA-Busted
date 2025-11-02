/*https://leetcode.com/problems/maximum-depth-of-binary-tree/*/

#include <iostream>
using namespace std;

class Solution
{
    int maxDepth(Node *root)
    {
        // base case
        if (root == NULL)
            return 0;
        // empty tree ke depth 0 hogi

        int leftAns = maxDepth(root->left);
        int rightAns = maxDepth(root->right);

        int finalDepth = 1 + max(leftAns, rightAns);

        return finalDepth;
    }

} int main()
{
    int a;
    cout << endl;
    return 0;
}
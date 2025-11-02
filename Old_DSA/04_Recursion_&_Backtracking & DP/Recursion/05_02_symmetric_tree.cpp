#include <iostream>
using namespace std;

class Solution
{
    bool checkmirror(Node *root1, Node *root2)
    {
        // base case

        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        if (root1 == NULL && root2 != NULL)
            return false;

        if (root1 != NULL && root2 == NULL)
            return false;

        // ab dono non null hain
        if (root1->val != root2->val)
            return false;

        bool op1 = checkmirror(root1->left, root2->right);
        bool op2 = checkmirror(root1->right, root2->left);

        bool finalAns = op1 && op2;
        return finalAns;
    }

    bool isSymmetric(Node *root)
    {
        if (root == NULL)
            return true;

        return checkmirror(root->left, root->right);
    }

}

int
main()
{
    int a;
    cout << endl;
    return 0;
}
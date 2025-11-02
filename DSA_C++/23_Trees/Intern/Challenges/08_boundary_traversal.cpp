#include <bits/stdc++.h>
using namespace std;

class Solution

{
public:
    void traversalLeft(Node *root, vector<int> &ans)
    {
        // base case check karo
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            // leaf node pe kuch nahi karna bas waps jana hain
            return;
        }

        // pehle store karo and then jaha jana hain waha jao

        ans.push_back(root->data);
        if (root->left)
        {
            traversalLeft(root->left,ans);
        }
        else
        {
            traversalLeft(root->right,ans);
        }
    }

    void traverseLeafNode(Node *root, vector<int> &ans)
    {
        // basea case

        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        traversalLeft(root->left, ans);
        traversalLeft(root->right, ans);
    }

    void traverseRightNode(Node *root, vector<int> &ans)
    {
        // base case
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            return;

        // aga node hain toh right mein jao and agar nahi hain tohh left mein jao
        if (root->right)
            traverseRightNode(root->right, ans);

        else
            traverseRightNode(root->left, ans);

        // wapas aate waqt store karlo
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {

        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        ans.push_back(root->data);

        // left part ka kam

        traversalLeft(root->left, ans);

        // traverse leaf node

        // leftsubtree
        traverseLeafNode(root->left, ans);

        // right subtree
        traverseLeafNode(root->right, ans);

        // traverse right wala part
        traverseRightNode(root->right, ans);

        return ans;
    }
}

int
main()
{
    int a;
    cout << endl;
    return 0;
}
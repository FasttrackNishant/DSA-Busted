#include <iostream>
using namespace std;

// diameter :- it is the longest path containing the maximum nodes
/*the longest path between any two end nodes    is called the max nodes
for and answer there can be three ways
1. leftsubtree --> diameter(root ->left)
2. rightsubtree --> diameter (root ->right)
3. mixing of the both sides
    -->  heightof(root ->left) + root(1) + heightof(root -> right)

    jo inka maximum hoga wahi ans



*/
int height(struct Node *Node)
{
    // base case
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

pair<int, int> diameterfast(Node *root)
{
    // base case toh same rahega

    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterfast(root->left);

    pair<int, int> right = diameterfast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int ans = max(op1,max( op2,) op3));

    // is example mein hume diameter ke sath sath height bhi call kar rahe hain toh humari complexity  ho jati hain o(n2) so ise kaise handle kare
    return ans;
}

int diameter(Node *root)
{
    return diameterfast(root).first;
}

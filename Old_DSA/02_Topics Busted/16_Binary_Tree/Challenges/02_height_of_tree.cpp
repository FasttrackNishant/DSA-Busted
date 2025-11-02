/*https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1*/


#include <iostream>

using namespace std;

// height of the binary  tree  height measn the maximum distance between the root node and the leaf node

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class solution
{
public:
    int height(struct Node *node)
    {
        // base case
        if (node == NULL)
        {
            return 0; 
        }

        // muze left ki height chahhiye

        int left = height(node->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }
};

Node *build_Tree(Node *root)
{

    cout << "enter The data :-" << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the da  ta for inserting in left " << data << endl;
    // Recursive call mardi
    root->left = build_Tree(root->left);

    cout << "Enter the data for inserting in right " << data << endl;
    root->right = build_Tree(root->right);

    return root;
}
int main()
{

    Node *root = NULL;
    root = build_Tree(root);
    solution ob;
    cout << ob.height(root) << endl;

    return 0;
}
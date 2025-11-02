#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *build_Tree(node *root)
{
    int data;
    cout << "Enter the data "
         << " ";
    cin >> data;

    root = new node(data);
    if (data == -1)
        return NULL;

    cout << "Enter the data for the left node " << data << endl;
    root->left = build_Tree(root->left);

    cout << "Enter the data for the right node " << data << endl;
    root->right = build_Tree(root->right);

    return root;
}

void inorder(node *root)
{
    // lnr

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    // N L R
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    // lrn

    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    cout << root->data << " ";
}
int main()
{
    node *root = NULL;

    root = build_Tree(root);
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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

void inorder(Node *root)
{
    // base case
    if (root == NULL)
        return;

    // inorder ->LNR

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    // NLR
    // base case

    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)

// LRN

{
    // base case
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// this will print the data in the one line
int main()
{
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    Node *root = NULL;
    root = build_Tree(root);

    cout << "Printing Inorder Traversal" << endl;
    inorder(root);

    cout << "Printing Preorder Traversal " << endl;
    preorder(root);

    cout << "printing post order traversal" << endl;
    postorder(root);

    return 0;
}
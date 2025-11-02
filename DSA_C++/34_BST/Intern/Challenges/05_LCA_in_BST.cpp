#include <iostream>
using namespace std;

Node *LCAinBST(Node *root, Node *P, Node *Q)
{

    // Iterative Way

    while (root != NULL)

    {
        if (root->data < P->data && root->data < Q->data)
            root = root->right;

        if (root->dat > P->data && root->data > Q->data)
            root = root->left;

        else
        {
            return root;
        }
    }

    // Recursive Way

    // base case
    if (root == NULL)
        return root;
    if (root->data < P->data && root->data < Q->data)
        return LCAinBST(root->right, P, Q);

    if (root->data > P->data && root->data > Q->data)
        return LCAinBST(root->left, P, Q);

    return root;
}

int main()
{
    int a;
    cout << endl;
    return 0;
}
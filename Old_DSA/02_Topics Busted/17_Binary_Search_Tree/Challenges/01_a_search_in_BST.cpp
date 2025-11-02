#include <iostream>
#include "Tree.h"
using namespace std;

bool searchInBST(Node *root, int x)
{
    // base case
    if (root == NULL)
    {
        return false;
    }
    // agar data mil gaya toh bhi ruk jao

    if (root->data == x)
    {
        return true;
    }

    if (root->data > x)
    {
        // left part mein search karo
        return searchInBST(root->left, x);
    }
    else
    { // right part mein
        return searchInBST(root->right, x);
    }
}



int main()
{
    int a;
    cout << endl;
    return 0;
}
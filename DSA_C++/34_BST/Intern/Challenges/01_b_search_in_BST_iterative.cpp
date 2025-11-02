#include <iostream>
using namespace std;

bool searchInBST(BinaryTreeNode<int> *root, int x)
{

    BinaryTreeNode<int> *temp = root;

    while (temp != NULL)
    {
        if (temp->data == x)
            return true;

        if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

int main()
{
    int a;
    cout << endl;
    return 0;
}
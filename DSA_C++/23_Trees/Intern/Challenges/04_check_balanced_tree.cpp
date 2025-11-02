#include <iostream>
using namespace std;

bool isBalaced(Node *root)
{
    // base case

    if (root == NULL)
    {
        return true;
    }

    bool left = isBalaced(root->left);
    bool right = isBalaced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

  
int main()
{
    int a;
    cout << endl;
    return 0;
}
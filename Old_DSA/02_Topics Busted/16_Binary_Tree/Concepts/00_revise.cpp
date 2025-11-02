    #include <iostream>
#include <queue>
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

node *build_tree(node *root)
{

    cout << "Enter the data " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    // left ka data

    cout << "Enter the data for the left node " << data << endl;
    root->left = build_tree(root->left);

    // right ka data

    cout << "Enter the data for the right node " << data << endl;
    root->right = build_tree(root->right);

    return root;
}
/*
ye walal code sirf ek line mein print karke de dega
void levelOrderTraversal(node *root)
{

    queue<node *> q;

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
*/

void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    node *root = NULL;

    root = build_tree(root);

    levelorder(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    return 0;
}
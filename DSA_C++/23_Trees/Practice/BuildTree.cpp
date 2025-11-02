#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    root = new Node(data);

    // left
    cout << " left of" << root->data << endl;
    root->left = buildTree(root->left);

    // right
    cout << "Enter data for right" << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
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

void printLevelOrderWithLine(Node *root)
{
    queue<Node *> q;
    q.push(root);

    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (!temp)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data;

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

    Node *root = buildTree(root);

    printLevelOrder(root);

    printLevelOrderWithLine(root);

    return 0;
}

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

    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for the left " << data << endl;
    root->left = build_Tree(root->left);
    cout << "Enter data for the right" << data << endl;
    root->right = build_Tree(root->right);

    return root;
}

// zig zag traversal

vector<int> zigzag(Node *root)
{
    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    queue<Node *> q;
    q.push(root);

    bool leftToright = true;
    while (!q.empty())
    {
        int size = q.size();

        vector<int> ans;

        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            int index = leftToright ? i : size - i - 1;

            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        // direction chage karni hogi

        leftToright = !leftToright;

        for (auto it : ans)
        {
            result.push_back(it);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

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
    Node *root = NULL;
    root = build_Tree(root);
    levelOrderTraversal(root);
    zigzag(root);

    for (int i = zigza; i < zigzag.end(); i++)
    {
        /* code */
    }
    
    
    return 0;
}
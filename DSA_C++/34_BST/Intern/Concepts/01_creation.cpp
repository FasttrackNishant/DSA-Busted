#include <bits/stdc++.h>
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

Node *minValue(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxValue(Node *root)
{
    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *insertIntoBST(Node *root, int d)
{
    // base case

    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // right part mein insert karo
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // left mein insert karna hain
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}
void levelordertraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    // yaha pe ek level complete ho chuki hain so ab seperator lagega

    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL) // ye check karega ki purana level complete ho chuka hain ya nahi
        {
            cout << endl;
            if (!q.empty()) // it means q has some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            // this conditon is checkin for non null
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

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node *deleteFromBST(Node *root, int val)
{
    // base case

    if (root == NULL)
        return root;

    // data mil gaya
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child

        // left child

        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;

            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)

    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    cout << "enter the data to create bst " << endl;
    takeInput(root);
    cout << "Printing the data " << endl;

    // inorder , preorder and postorder try karo
    cout << "Minimum value is " << minValue(root)->data << endl;
    cout << "Maximum value is " << maxValue(root)->data << endl;

    levelordertraversal(root);
    root = deleteFromBST(root, 60);
    cout << endl;
    levelordertraversal(root);

    // 21 10 50 5 15 40 60 35 70 -1

    return 0;
}
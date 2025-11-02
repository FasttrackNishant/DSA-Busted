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

node *build_Tree(node *root)
{

    cout << "enter The data :-" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data for inserting in left " << data << endl;
    // Recursive call mardi
    root->left = build_Tree(root->left);

    cout << "Enter the data for inserting in right " << data << endl;
    root->right = build_Tree(root->right);

    return root;
}
//this will print the data in the one line

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


//this is by using the seperator
void levelordertraversal(node *root)
{
    queue<node *> q;

    q.push(root);
    // yaha pe ek level complete ho chuki hain so ab seperator lagega

    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();

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
void inorder(node *root)
{
    // base case
    if (root == NULL)
        return;

    inorder(root->left);
    // N ko print karde
    cout << root->data << " ";

    // ab Right mein ja

    inorder(root->right);
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    root = build_Tree(root);

    levelordertraversal(root);

    cout << "Inorder traversal is " << endl;
    inorder(root);
    return 0;
}
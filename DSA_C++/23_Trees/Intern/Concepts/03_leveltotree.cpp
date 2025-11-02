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

node *buildfromlevel(node *&root)
{
    queue<node *> q;

    cout << "Enter the data for the root " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter the left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the data for the right node " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}


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
int main()
{
    node *root = NULL;

    buildfromlevel(root);
    levelordertraversal(root);
    return 0;
}
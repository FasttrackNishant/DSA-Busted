

/*https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=1*/ #include <iostream> using namespace std;

Node *flatten(Node *root)
{
    vector<int> inorderVal;

    inorder(root, inorderVal);
    int n = inorderVal.size();

    Node *newRoot = new Node(inorderVal[0]);

    Node *curr = newRoot;

    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    //  3rd step last node ke dono NULL karde

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

int main()
{
    int a;
    cout << endl;
    return 0;
}
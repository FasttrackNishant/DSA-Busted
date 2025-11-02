#include <iostream>
using namespace std;

class Solution

{
public:
    int findPosition(int in[], int element, int n)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     if (in[i] == element)
        //         return i;
        // }
        // return -1;
    }

    int createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {

        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
    }

    Node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
    {
        // base case
        //  pura array cover kar liya hain in ke index  ne
        if (index >= n || inOrderStart > inOrderEnd)

        {
            return NULL;
        }

        // create a root node for an element
        int element = pre[index++];
        Node *root = new Node(element);
        // is node ki position find out karo
        // int position = findPosition(in, element, n);

        // to find element  index in inorder
        int position = nodeToIndex[element];

        // recursive call maro ab

        root->left = solve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n)
    {
        int preOrderIndex = 0;
        // create node
        map<int, int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
        Node *ans = solve(in, pre, preOrderIndex, 0 /*string index of inorder */, n - 1, /*ending index of inorder*/ n, nodeToIndex);

        return ans;
    }
};

int main()
{
    int a;
    cout << endl;
    return 0;
}
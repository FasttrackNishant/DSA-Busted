#include <iostream>
using namespace std;

class solution
{
public:
    pair<bool, int> sumTreeFast(Node *root)
    {
        // base case

        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
            // yaha root ki value 0 hain
        }

        // leaves
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftAns = sumTreeFast(root->left);
        pair<bool, int> rightAns = sumTreeFast(root->right);

        // ab is stage mein mere pass pair aayi hai usme ans hain ki true hain ya nahi and the value hain us node ki ab muze check karna hain

        bool isleftSumTree = leftAns.first;
        bool isrightSumTree = rightAns.first;

        int leftSumVal = leftAns.second;
        int rightSumVal = rightAns.second;

        bool condition = root->data == leftSumVal + rightSumVal;

        pair<bool, int> ans;

        if (isleftSumTree && isrightSumTree && condition)
        {
            ans.first = true;
            ans.second = root->data + leftSumVal + rightSumVal;
            // or
            // ans.second = 2 * root->data;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
}

bool
isSumTree(Node *root)
{
    return sumTreeFast(root).first;
}

int main()
{
    int a;
    cout << d endl;
    return 0;
}
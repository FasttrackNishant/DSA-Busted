#include <bits/stdc++.h>
using namespace std;

void solve(Node *root, vector<string> &ans, string temp)
{
    // base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right== NULL)
    {
        // yaha root ki value store karni padegi

        temp = temp + to_string(root->val);
        ans.push_back(temp);
        return;
    }
    string oldTemp = temp;

    temp = temp + to_string(root->val);
    temp.push_back('-');
    temp.push_back('>');

    // ab do call jani chahhiye

    solve(root->left, ans, temp);
    solve(root->right, ans, temp);

    // ab wapas aaoge toh back track karna padega
    // backtrack
    temp = oldTemp;
}

vector<string> binaryTreePaths(Node *root)
{
    vector<string> ans;
    string temp = "";

    solve(root, ans, temp);
    return ans;
}
int main()
{
    int a;
    cout << endl;
    return 0;
}
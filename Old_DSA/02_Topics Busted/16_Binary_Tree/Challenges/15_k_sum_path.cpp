#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(Node *root, int k, int &count, vector<int> path)
    {
        // bas case

        if (root == NULL)
            return;

        path.push_back(root->data);

        // left
        solve(root->left, k, count, path);

        // right

        solve(root->right, k, count, path);

        // check of  k sum
        int size = path.size();
        int sum = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }
        // ab upar jate waqt vector kam hona chhahiye

        path.pop_back();
    }

    int sumK(Node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};
int main()
{
    int a;
    cout << endl;
    return 0;
}
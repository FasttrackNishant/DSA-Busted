#include <bits/stdc++.h>
using namespace std;

// yaha sirf ek condition nikalni hain

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;

        // base case
        if (root == NULL)
            return ans;

        map<int, int> topNode;

        queue<pair<Node *, int>> q;

        q.push(make_pair(root, 0));
        // toh yaha first node push ho gayi queue mein

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second;

            // maintain one to one mapping
           
                topNode[hd] = frontNode->data;
            

            if (frontNode->left)
                q.push(make_pair(frontNode->left, hd - 1));

            if (frontNode->right)
                q.push(make_pair(frontNode->right, hd + 1));
        }

        for (auto i : topNode)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main()
{
    int a;
    cout << endl;
    return 0;
}
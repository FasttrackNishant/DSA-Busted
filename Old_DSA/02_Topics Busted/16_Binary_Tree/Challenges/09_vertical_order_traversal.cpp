#include <bits/stdc++.h>
using namespace std;

class Solution

{
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int>>> nodes;

        queue<pair<Node *, pair<int, int>>> q;
        vector<int> ans;

        if (root == NULL)
            return ans;

        q.push(make_pair(root, make_pair(0, 0)));
        // this is for the first line where level and horizontal distance is zero

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> temp = q.front();
q.pop();
            Node *frontNode = temp.first;

            int hd = temp.second.first;
            int lvl = temp.second.second;

            // ab bas mapping kardo

            nodes[hd][lvl].push_back(frontNode->data);

            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }

            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }
        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
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
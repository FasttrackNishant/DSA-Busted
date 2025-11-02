#include <bits/stdc++.h>;
using namespace std;

class solution

{
public:
    vector<int> zigzag(Node *root)
    {
        vector<int> result;
        if (root == NULL)
            return ans;
        queue<Node *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            // har ek level ko process karna hain jab tak queue empty nahi hoti
            int size = q.size();
            vector<int> ans(size);
            for (int i = 0; i < size; i++)
            {
                Node *frontNode = q.front();
                q.pop();
                // ab ans mein element dalenge do rasto se
                //normal dalo ya reverse dalo
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;
                if (frontNode->left)
                {
                    q.push(frontNode->left);
                }
                if (frontNode->right)
                {
                    q.push(frontNode->right);
                }
            }
            // ab yaha direction change karni padegi na
            leftToRight = !leftToRight;
            for (auto i : ans)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    int a;
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// =
vector<int> nextsmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &v)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());
    // left to right

    for (int i = 0; i < v.size(); i++)
    {
        int curr = v[i];
        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int getRectangularArea(vector<int> &height)
{
    // step  1 : prevsmaller ka output
    vector<int> prev = prevSmallerElement(height);

    // step 2 : nextsmaller ka nikalo
    vector<int> next = nextsmaller(height);

    // area find karenge
    int maxArea = INT_MIN;
    int size = height.size();
    for (int i = 0; i < height.size(); i++)
    {
        int length = height[i];

        // ab woh next smaller mein last mein size ka issue agar wahi solve kiya toh ans nahi aayega so yaha tackle karte hain
        if (next[i] == -1)
        {
            next[i] = size;
        }
        int width = next[i] - prev[i] - 1;

        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    int ans = getRectangularArea(v);
    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// =

int solve(vector<int> val, vector<int> wt, int index, int capacity, vector<vector<int>> dp)
{
    // base case

    if (index == val.size() || capacity == 0)
        return 0;

    if (dp[index][capacity] != -1)

        return dp[index][capacity];
    int include = 0;

    if (capacity >= wt[index])
    {
        include = val[index] + solve(val, wt, index + 1, capacity - wt[index], dp);
    }

    int exclude = 0 + solve(val, wt, index + 1, capacity, dp);

    return dp[index][capacity] = max(include, exclude);
}

int solveTab(vector<int> val, vector<int> wt, int C, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int capacity = 0; capacity <= C; capacity++)
        {
            int include = 0;

            if (capacity >= wt[index])
            {
                include = val[index] + dp[index + 1][capacity - wt[index]];
            }

            int exclude = 0 + dp[index + 1][capacity];

            dp[index][capacity] = max(include, exclude);
        }
    }
    return dp[0][C];
}

int main()
{
    int n = 4;
    vector<int> val, wt;

    // val.push_back(60);
    // val.push_back(100);
    // val.push_back(120);

    val.push_back(5);
    val.push_back(4);
    val.push_back(8);
    val.push_back(6);

    // wt.push_back(10);
    // wt.push_back(20);
    // wt.push_back(30);

    wt.push_back(1);
    wt.push_back(2);
    wt.push_back(4);
    wt.push_back(5);

    int capacity = 5;

    vector<vector<int>> dp(3, vector<int>(capacity + 1, -1));
    // int ans = solve(val, wt, 0, capacity, dp);
    int ans = solveTab(val, wt, capacity, n);
    cout << ans << endl;
    return 0;
}
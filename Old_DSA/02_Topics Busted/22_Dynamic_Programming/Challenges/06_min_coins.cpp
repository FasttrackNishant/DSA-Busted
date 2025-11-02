#include <bits/stdc++.h>
using namespace std;
// =

int minCoinsMem(int target, vector<int> &arr, vector<int> dp)
{
    if (target == 0)
        return 0;

    if (target < 0)
        return INT_MAX;

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        int ans = minCoinsMem(target - arr[i], arr, dp);

        // if ans is valid then update mini
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return dp[target] = mini;
}

int minCoins(int target, vector<int> arr)
{
    if (target == 0)
        return 0;

    if (target < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        int ans = minCoins(target - arr[i], arr);

        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}

int minCoinsTab(vector<int> &arr, int t)
{
    vector<int> dp(t, INT_MAX);
    dp[0] = 0;

    for (int target = 1; target <= t; target++)
    {
        int mini = INT_MAX;

        for (int i = 0; i < arr.size(); i++)
        {
            if (target - arr[i] >= 0)
            {
                int ans = dp[target - arr[i]];

                if (ans != INT_MAX)
                {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        dp[target] = mini;
    }
    return dp[t];
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    int target = 7;
    vector<int> dp(target + 1, -1);

    cout << minCoins(target, arr) << endl;
    cout << minCoinsMem(target, arr, dp) << endl;
    cout << minCoinsTab(arr, target) << endl;
}
#include <bits/stdc++.h>
using namespace std;

// isme tle aayega

class Solution
{
public:
    int solve(vector<int> &cost, int n)
    {
        // base case
        if (n == 0)
            return cost[0];

        if (n == 1)
            return cost[1];

        int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
        return ans;
    }

    int solvedp(vector<int> &cost, int n, vector<int> &dp)
    {
        // base case
        if (n == 0)
            return cost[0];

        if (n == 1)
            return cost[1];

        // step 3
        if (dp[n] != -1)
            return dp[n];

        // step 2

        dp[n] = cost[n] + min(solvedp(cost, n - 1, dp), solvedp(cost, n - 2, dp));
        return dp[n];
    }

    int solveTab(vector<int> &cost, int n)

    {

        // step1 = creation of dp array;
        vector<int> dp(n + 1);

        // step 2 = conclude from recursive relation
        dp[0] = cost[0];
        dp[1] = cost[1];

        // 3 rd step
        for (int i = 2; i < n - 1; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }

    int solvespace(vector<int> &cost, int n)
    {
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
    // int minCostClimbingStairs(vector<int> &cost)
    // {
    //     int n = cost.size();
    //     int ans = min(solve(cost, n - 1), solve(cost, n - 2));
    //     return ans;
    // }

    // --> for dp
    // int minCostClimbingStairs(vector<int> &cost)
    // {

    //     int n = cost.size();
    //     // step 1: dp array create karo
    //     vector<int> dp(n + 1, -1);

    //     int ans = min(solvedp(cost, n - 1, dp), solvedp(cost, n - 2, dp));
    //     return ans;
    // }

    //  -->  for tabulation
    // int n = cost.size();
    // return solveTab(cost, n);

    //->space optimization
    // int n = cost.size();
    // return solvespace(cost, n);
};

int main()
{
    int a;
    cout << endl;
    return 0;
}
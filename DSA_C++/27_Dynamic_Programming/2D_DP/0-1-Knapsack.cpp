#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int W, const vector<int>& cost, const vector<int>& wt, int index, vector<vector<int>>& dp) {
        if (index < 0 || W == 0) return 0; // base case [web:1]
        if (dp[index][W] != -1) return dp[index][W]; // memoization check [web:1]

        int include = 0;
        // Optional trace to see recursion and memo hits
        
        if (wt[index] <= W) {
            include = cost[index] + solve(W - wt[index], cost, wt, index - 1, dp); // include case [web:1]
        }
        int exclude = solve(W, cost, wt, index - 1, dp); // exclude case [web:1]

        int ans = max(include, exclude); // choose best [web:1]
        dp[index][W] = ans; // store in memo [web:1]
        cout << index << "--" << W << " Value -> " << dp[index][W] << endl; // dp is -1 before compute
        return ans;
    }

    int knapsack(int W, const vector<int>& val, const vector<int>& wt) {
        int n = static_cast<int>(wt.size());
        vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // n x (W+1) memo table [web:1]
        int ans = solve(W, val, wt, n - 1, dp);

        // Optional: print DP table
        for (const auto& row : dp) {
            for (int cell : row) cout << " " << cell;
            cout << '\n';
        }

        return ans;
    }
};

int main() {
    // Example 1
    int W1 = 5;
    vector<int> val1 = {10,40,30,50};
    vector<int> wt1  = {5,4,2,3};
    Solution s;
    cout << "Max value (example 1): " << s.knapsack(W1, val1, wt1) << '\n'; // Expected 3 [web:1]

    // // Example 2
    // int W2 = 7;
    // vector<int> val2 = {60, 100, 120};
    // vector<int> wt2  = {1, 3, 4};
    // cout << "Max value (example 2): " << s.knapsack(W2, val2, wt2) << '\n'; // Standard variant [web:8]

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if (n <= 1)
        return n;

    int ans = solve(n - 1) + solve(n - 2);
    // answer store karlo

    return ans;
}

// Recursion + Memorisation
int solveMem(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = solveMem(n - 1, dp) + solveMem(n - 2, dp);
    return dp[n] = ans;
}

// Bottom Up approach
// step 1 :- dp array creation

// step 2 :-  base case pe analysis pe Rec code and update array accordingly

// step 3 :-  find the range for the changing variable and copy paste the logic in the rec code accordingly

int solveTab(int n)
{
    // create dp array
    vector<int> dp(n + 1, 0);
    // base case se dp array update karo
    dp[0] = 0;
    dp[1] = 1;

    // step 3 loop 2 se s   tart kiya as hume ans pata hain 0 & 1 ke
    for (int i = 2; i <= n; i++)
    {

        int ans = dp[i - 1] + dp[i - 2];
        dp[i] = ans;
    }

    return dp[n];
}
// space optimization ka method

int solveTabSO(int n)
{
    // create dp array

    int prev1 = 1;
    int prev2 = 0;
    int curr;

    // step 3 loop 2 se s   tart kiya as hume ans pata hain 0 & 1 ke
    for (int i = 2; i <= n; i++)
    {

        int ans = prev1 + prev2;
        curr = ans;
        prev2 = prev1 ;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    cout << "Enter the value " << endl;
    cin >> n;

    // step 1:- create dp array
    vector<int> dp(n + 1, -1);

    // int ans = solveMem(n, dp);
    int ans = solveTabSO(n);

    cout << "ans is -> " << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// =

int solve(int n, int a, int b, int c)

{
    // base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    int first = solve(n - a, a, b, c);
    int second = solve(n - b, a, b, c);
    int third = solve(n - c, a, b, c);

    return 1 + max(first, max(second, third));
}

int solveMem(int n, int a, int b, int c, vector<int> dp)
{
    if (n == 0)
        return 0;

    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int first = solveMem(n - a, a, b, c, dp);
    int second = solveMem(n - b, a, b, c, dp);
    int third = solveMem(n - c, a, b, c, dp);


    return dp[n] = 1 + max(first, max(second, third));
}

int main()
{
    int n = 10;
    int a = 2;
    int b = 7;
    int c = 11;

    // for memoisation
    vector<int> dp(n+1, -1);

    // int ans = solve(n, a, b, c);
    int ans = solveMem(n, a, b, c, dp);
    if (ans <= 0)
    {
        ans = -1;
    }

    cout << "max cuts are " << ans << endl;
    return 0;
}
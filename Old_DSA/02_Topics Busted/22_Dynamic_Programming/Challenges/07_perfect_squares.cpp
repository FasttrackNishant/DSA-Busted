#include <bits/stdc++.h>
using namespace std;
// =

int perfectSquare(int n)
{
    if (n == 0)
        return 0;

    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + perfectSquare(n - i * i));
    }
    return ans;
}
int perfectSquareMem(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    int ans = INT_MAX;

    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + perfectSquareMem(n - i * i, dp));
    }

    dp[n] = ans;

    return dp[n];
}
int perfectSquareTab(int N)
{
    // create dp array
    vector<int> dp(N + 1, 0);

    for (int n = 1; n <= N; n++)
    {

        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + dp[n - i * i]);
        }
        dp[n] = ans;
    }
    return dp[N];
}

int main()
{
    int n = 12;
    vector<int> dp(n + 1, -1);
    cout << perfectSquare(n) << endl;
    cout << perfectSquareMem(n, dp) << endl;
    cout << perfectSquareTab(n) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
    // base case
    if (n == 1)
        return 0;

    return (solve(n - 1, k) + k) % n;
}

int findtheWinner(int n, int k)
{
    int ans = solve(n, k) + 1;
    return ans;
}
int main()
{
    int a;
    cout << endl;
    return 0;
}
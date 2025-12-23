#include <iostream>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if(n==0) return 0;

    if(dp[n] != -1) return dp[n];

    int ans = n ;
    for(int i = 1 ; i * i <= n ; i++)
    {
        int call = 1 + solve(n-(i*i));

        dp[n] = min(ans,call);
    }

    return dp[n];
}


int main() {
    int n= 5;
    vector<int>
    int ans = solve(n);
    cout<<ans;
    return 0;
}
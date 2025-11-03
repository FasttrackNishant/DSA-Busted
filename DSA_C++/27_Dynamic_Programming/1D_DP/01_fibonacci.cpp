#include <iostream>
#include <vector>
using namespace std;

int solve(int n){

    if(n<=1) return n;

    return solve(n-1) + solve(n-2);

}

int solveMem(int n , vector<int> &dp)
{
    if(n<=1) 
        return n;

    if(dp[n] != 1)
    {
        return dp[n];
    }

    dp[n] = solveMem(n-1,dp)+ solveMem(n-1,dp);

    return dp[n];
}


int solveTab(int n)
{
    if(n==0) return 0;

    vector<int> dp(n+1,0);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n ;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


int solveSpaceOpt(int n)
{    
    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i <=n ;i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {

    int n ; 
    cin>>n;
    cout << solve(n);

    // Mem
    // vector<int> dp(n+1,-1);
    // solveMem(n,dp);

    return 0;
}
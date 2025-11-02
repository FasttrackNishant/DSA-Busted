#define MOD = 100000007

#include <bits/stdc++.h>
using namespace std;

/*Ye tle marega

*/
int solve(long long nStairs, int i)

{
    // base case
    if (i == nStairs)
    {
        return 1;
    }
    // aagar aage badh gaya
    if (i > nStairs)
    {
        return 0;
    }

    return (solve(nStairs, i + 1) + solve(nStairs, i + 2)) % MOD;
}

int countDistinctWayToClimbStair(long long nStairs)
{

    return solve(nStairs, 0);
}

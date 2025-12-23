#include <iostream>
#include <vector>
using namespace std;

int solveTab(int n , int last ,vector<vector<int>> pts)
{
    vector<int> dp(n,0);

    // base 
    dp[0] = max(pts[0][1],pts[0][2]);
    dp[1] = max(pts[0][0],pts[0][2]);
    dp[2] = max(pts[0][0],pts[0][1]);
    dp[3] = max(pts[0][1],max(pts[0][2],pts[0][3]));

    // days -> task -> dp

    for(int day = 0 ; day < n ; day ++)
    {
        vector<int> temp(4,0);
        for(int task = 0 ; task < 3 ; task++)
        {
            // dp[day][task];
            if(last != task)
            {
                int point = pts[day][task] + dp[task];

                temp[last] = max(temp[task],point);
            }
        }

        dp = temp ;
    }

    return dp[3];
}



}

int main() {
    
    return 0;
}


int solve(int day, vector<vector<int>>&points , int last , vector<vector<int>>&dp)
{
    if(day == 0)    
    {
        // find max
        int maxi = 0;
        for(int task = 0 ;task < 3 ; task++)  
        {
            if(task != last)
                maxi = max(maxi,points[0][task]);
        }

        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];
 
    // remaining
    int ans = 0;
    for(int i = 0 ; i < 3 ; i++)
    {
        if(i != last)
        {
            ans = max(ans,points[day][i] + solve(day-1,points,i,dp));
        } 
    }

    dp[day][last] = ans;
    return dp[day][last] ;

}


int solveTab(int n , int last ,vector<vector<int>> pts)
{
    vector<vector<int>> dp(n,vector<int>(4,0));

    // base 
    dp[0][0] = max(pts[0][1],pts[0][2]);
    dp[0][1] = max(pts[0][0],pts[0][2]);
    dp[0][2] = max(pts[0][0],pts[0][1]);
    dp[0][3] = max(pts[0][1],max(pts[0][2],pts[0][3]));

    // days -> task -> dp

    for(int day = 1 ; day < n ; day ++)
    {
        for(int last = 0 ; last < 4 ; last++)
        {
                for(int task = 0 ; task < 3 ; task++)
                {

                if(last != task)
                    // dp[day][task];
                    {
                        int point = pts[day][task] + dp[day-1][task];

                        dp[day][last] = max(dp[day][last],point);
                    }
                }
        }
    }

    return dp[n-1][3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1,vector<int>(4,-1));
//    return solve(n-1,points,3,dp);
    return solveTab(n,3,points);
}
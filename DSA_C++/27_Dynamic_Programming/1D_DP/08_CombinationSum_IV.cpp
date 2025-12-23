#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> nums , int target,vector<int>&dp)
{
    cout<<"Call for Target "<<target<<endl;
    if(target == 0) return 1;

    if(target < 0) return 0;

    if(dp[target] != -1) 
    {
        cout<<"Skip for"<<target<<endl;
     return dp[target];
    }

    int sum = 0 ;

    for(int i = 0 ; i < nums.size() ; i++)
    {
        cout<<"Call for index"<<i<<endl;
        int ans = solve(nums,target-nums[i],dp);
        cout<<"Ans Value "<<ans<<endl;
        sum += ans;
        cout << "Sum Value "<<sum<<endl;
        dp[target] = sum;
        cout<<"Sum put for target "<<target<<"->"<<sum<<endl;
    }
 
    return dp[target];
}

int main() {

    vector<int> nums = {1,2,3};
    int target = 4;
    vector<int> dp(target+1,-1);

    int ans = solve(nums,target,dp);

    for(auto it : dp){
        cout<<it<<" ";
    }
    cout<<ans;
    
    return 0;
}
class Solution {
public:

    void solve(vector<int> & nums , int index , int target , vector<int> &level , vector<vector<int>> &ans)
    {
        // base case
        if(index == nums.size())
            return;

        if(target == 0 ){
            ans.push_back(level);
            return;}

        //include 
        if(nums[index] <= target)
        {
            level.push_back(nums[index]);
            solve(nums,index,target-nums[index],level,ans);
            level.pop_back();
        }

        solve(nums,index+1 , target , level , ans);

        //exclude

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> level;
        vector<vector<int>> ans ;

        solve(candidates , 0 , target , level ,ans);
        return ans;
        
    }
};
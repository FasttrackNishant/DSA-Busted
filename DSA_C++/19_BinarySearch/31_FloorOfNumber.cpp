class Solution {
  public:
    int findFloor(vector<int>& nums, int x) {
        
        int ans = -1;
        
        int n = nums.size();
        
        int start = 0;
        int end = n -1;
        
        while(start <= end)
        {
            int mid = start + ( end - start)/2;
            
          
             
            if(nums[mid] <= x)
            {
                  ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        return ans;
    }
};

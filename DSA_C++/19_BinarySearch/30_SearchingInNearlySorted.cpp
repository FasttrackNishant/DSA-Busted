#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    
    return 0;
}

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& nums, int target) {
       
        int n = nums.size();
            
        if(n==1 && nums[0] == target)
        {
            return 0;
        }
        
        if(nums[0] == target && nums[1] == target) return 0;
        
        if(nums[n-1] == target && nums[n-2] == target) return n-1;
        
        int start = 1;
        int end = n -2;
        
        while(start <=end)
        {
            int mid = start + ( end - start )/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid-1] == target )
            {
                return mid-1;
            }
            else if(nums[mid+1] == target)
            {
                return mid+1;
            }
            
            if(nums[mid] < target )
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        return -1;
        
    }
};
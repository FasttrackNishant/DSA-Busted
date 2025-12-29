#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    
    return 0;
}
    

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if(n==1)
            return nums[0];

        for(int i =0 ; i < n ;i++)
        {
            if(i == 0)
            {
                if(nums[i] != nums[i+1])
                    return nums[i];
            }
            else if(i == n-1)
            {
                if(nums[i] != nums[i-1])
                    return nums[i];
            }   
            else
            {
                if(nums[i] != nums[i+1] && nums[i] != nums[i-1])
                    return nums[i];
            }
        }

        return -1;
    }
};







class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int xorvar = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            ans = xorvar ^ nums[i];
            xorvar = ans;

        }
        
        return ans;
    }
};





class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        if(nums[0] != nums[1]) return nums[0];

        if(nums[n-1] != nums[n-2]) return nums[n-1];    

        // search space kam kar di

        int start = 1;
        int end = n-2;

        while(start <= end)
        {

            int mid = start + (end - start ) /2;

            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
                return nums[mid];

            // agar element aa gya toh index gadbad ho jete hain nahi toh normal rehte hain

            // agar mein odd index pe ho , mera pehla wala same hain -> 
            // it means element ab tak aaya nahi hain
            // left mein ans nahi hani  , right mein hain
            // agar even index pe ho , mera right wala same hain ->left mein ans nahi  hain right mein hoga
            // elimination
            if(mid % 2 == 1 && nums[mid-1] == nums[mid] || ( mid % 2 == 0 && nums[mid] == nums[mid+1]))
            {              
                start = mid + 1;
            }
            else 
            {
                end = mid -1;
            }

        }

        return -1;
        
    }

};
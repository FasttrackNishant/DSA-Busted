#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    
    return 0;
}


class Solution {
  public:
    int findKRotation(vector<int> &nums) {

        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = INT_MAX;
        int index = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;


            // this is the optimization
            // if all are sorted
            if (nums[start] <= nums[end]) {
                
                if(nums[start] < ans)
                {
                    ans = nums[start];
                    index = start;
                }
              
                break;
            }

            // check for the sorted portion

            if (nums[start] <= nums[mid]) {
                
                if(nums[start] < ans)
                {
                    ans = nums[start];
                    index = start;
                }
                
                start = mid + 1;

            } else {

                if(nums[mid] < ans)
                {
                    ans = nums[mid];
                    index = mid;
                }
                
                end = mid - 1;
            }
        }

        return index;
    }
};

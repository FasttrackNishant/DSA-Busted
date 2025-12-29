#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start) / 2;


            // this is the optimization
            // if all are sorted
            if (nums[start] <= nums[end]) {
                ans = min(ans, nums[start]);
                break;
            }

            // check for the sorted portion

            if (nums[start] <= nums[mid]) {

                ans = min(ans, nums[start]);
                start = mid + 1;

            } else {

                ans = min(ans, nums[mid]);
                end = mid - 1;
            }
        }

        return ans;
    }
};
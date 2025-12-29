// try to approach duplicate problems first by the unique find out what is not working then only accordinlgy adopt the condition
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    
    return 0;
}

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // this is only condition to be added becuase this is giving problem
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start = start + 1;
                end = end - 1;
                continue;
            }

            // check for sorted portion

            if (nums[start] <= nums[mid]) {
                // left sorted
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }

            } else {
                // right sorted
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return false;
    }
};


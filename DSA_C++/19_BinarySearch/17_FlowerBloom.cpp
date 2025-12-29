class Solution {
public:
    bool possible(vector<int> &nums, int m, int k, int day) {
        int count = 0;
        int boks = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= day) {
                count++;
                if(count == k) {
                    boks++;
                    count = 0;
                    if(boks >= m) return true;  // Early return if we have enough bouquets
                }
            } else {
                count = 0;
            }
        }
        
        return boks >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded = (long long)m * k;
        int n = bloomDay.size();
        
        // Check if it's even possible
        if(totalFlowersNeeded > n) {
            return -1;
        }
        
        // Find min and max days
        int minDay = INT_MAX;
        int maxDay = INT_MIN;
        for(int day : bloomDay) {
            minDay = min(minDay, day);
            maxDay = max(maxDay, day);
        }
        
        int start = minDay;
        int end = maxDay;
        
        // Binary search for minimum day
        while(start < end) {
            int mid = start + (end - start) / 2;
            
            if(possible(bloomDay, m, k, mid)) {
                end = mid;  // Try to find a smaller day that works
            } else {
                start = mid + 1;  // Need to wait longer
            }
        }
        
        return start;
    }
};
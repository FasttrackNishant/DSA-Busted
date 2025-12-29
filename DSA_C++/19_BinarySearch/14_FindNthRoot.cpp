class Solution {
public:
    long long int helper(int n, int m) {
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= m;
            // Prevent overflow
            if (ans > 1e9) return ans; // Return early if we exceed m
        }
        return ans;
    }

    int nthRoot(int n, int m) {
        if (m == 0) return 0;
        if (n == 1) return m;
        
        int low = 1, high = m;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long power = helper(n, mid);
            
            if (power == m) {
                return mid; // Found exact nth root
            } else if (power < m) {
                low = mid + 1; // Try larger number
            } else {
                high = mid - 1; // Try smaller number
            }
        }
        
        return -1; // No integer nth root found
    }
};
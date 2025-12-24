class Solution {
public:
    bool knows(vector<vector<int>>& M, int a, int b) {
        return M[a][b] == 1;
    }

    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return -1;
        
        stack<int> s;
        
        // Step 1: Push all people onto stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        
        // Step 2: Elimination process - compare pairs
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            // If a knows b, then a cannot be celebrity (celebrity knows no one)
            // If a doesn't know b, then b cannot be celebrity (everyone must know celebrity)
            if (knows(M, a, b)) {
                s.push(b); // a knows b, so a is not celebrity
            } else {
                s.push(a); // a doesn't know b, so b is not celebrity
            }
        }
        
        int candidate = s.top();
        
        // Step 3: Verify the candidate
        // Check 1: Candidate should know nobody
        for (int i = 0; i < n; i++) {
            if (candidate != i && M[candidate][i] == 1) {
                return -1;
            }
        }
        
        // Check 2: Everyone should know candidate (except themselves)
        for (int i = 0; i < n; i++) {
            if (candidate != i && M[i][candidate] == 0) {
                return -1;
            }
        }
        
        return candidate;
    }
};
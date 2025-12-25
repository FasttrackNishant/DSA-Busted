class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        string ans = "";
        int n = s.length();
        if (n == 0) return ans;
        
        queue<char> q;
        vector<int> freq(26, 0); // Assuming lowercase English letters only
        // If string can have other characters, use map<char, int> instead
        
        for (int i = 0; i < n; i++) {
            // Update frequency
            freq[s[i] - 'a']++;
            
            // If this is first occurrence, add to queue
            if (freq[s[i] - 'a'] == 1) {
                q.push(s[i]);
            }
            
            // Remove characters from front of queue if they repeat
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
            
            // Append to answer
            if (!q.empty()) {
                ans += q.front();
            } else {
                ans += '#';
            }
        }
        
        return ans;
    }
};
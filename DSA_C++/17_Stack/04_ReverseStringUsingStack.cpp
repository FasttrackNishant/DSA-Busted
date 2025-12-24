class Solution {
  public:
    string reverse(const string& S) {
        
        stack<char> st;
        string ans ; 
        
        for(auto it : S)
        {
            st.push(it);
        }
        
        while(!st.empty())
        {
            char top  = st.top();
            ans += top;
            st.pop();
        }
        
        
        return ans;
        
        
    }
};

/*
Time complexity = > O(2N);
Space will -> O(N)
*/
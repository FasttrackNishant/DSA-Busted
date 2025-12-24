class Solution {
  public:
  
    void solve(stack<int> &st , int count , int mid)
    {
        if(count == mid )
        {
            st.pop();
            return;
        }
        
        int num = st.top();
        st.pop();
        
        solve(st, count+1 , mid);
        
        st.push(num);
        
        
    }
    
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        
        int count = 0;
        int mid = s.size()/2;
        
        solve(s,count,mid);
        
    }
};

/*

TC -> O(N)
SC -> O(2N)

*/
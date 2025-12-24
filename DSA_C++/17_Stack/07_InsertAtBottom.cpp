// User function Template for C++

class Solution {
  public:
    void solve(stack<int> &st , int count ,int size ,int x)
    {
        if(st.empty())
        {
            st.push(x);
            return ;
        }
        
        int num = st.top();
        st.pop();
        
        solve(st,count+1,size , x);
        
        st.push(num);
        
    }
  
    stack<int> insertAtBottom(stack<int> st, int x) {
        
        int count =0;
        int size =st.size();
        solve(st,count,size,x);
        return st;
        
    }
};
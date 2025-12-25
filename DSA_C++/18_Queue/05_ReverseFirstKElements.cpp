/* Iterative  */
// TLE


class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        
        stack<int> st;
        int n = q.size();
    
        int i = 0;
        while(i < k )
        {
            int front = q.front();
            q.pop();
            
            st.push(front);
            i++;
            
        }
        
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            q.push(top);
        }
        
        int diff = n - k;
        
        while(diff--)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        
        return q;
        
    }
};

/* Recursive Solution */

class Solution {
  public:
  
    void solve(queue<int> &q , int k )
    {
        if(k == 0) return ;
        
        int front = q.front();
        q.pop();
        
        solve(q,k-1);
        
        q.push(front);
        
    }
    
    queue<int> reverseFirstK(queue<int> q, int k) {
        
        int n = q.size();
        
        if (n < k) return q;
        
        solve(q,k);
        
        for(int i =  0 ; i < n-k ; i++)
        {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
class Solution {
  public:
    bool checkRedundancy(string &s) {
        
        stack<char> st;
        
        for(auto it : s)
        {
            if(it == '(' || it == '+' || it == '-' || it == '*' || it == '/')
            {
                st.push(it);
            }
            else if(it == ')')
            {
                // check for ( and +)
                
                bool isRed = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                        isRed = false;
                        
                    st.pop();
                    
                }
                
                if(isRed)
                    return true;
                
                st.pop();
            }
            
            
        }
        
        return false;
    }
};

class Solution {
  public:
  
    void insertAtBottom(stack<int> &st,int element)
    {
        if(st.size() == 0)    
        {
            st.push(element);
            return;
        }
        
        int num = st.top();
        st.pop();
        
        insertAtBottom(st,element);
        
        st.push(num);
    }
    
    
    void reverseStack(stack<int> &st) {
        
        if(st.empty()) return;
        
        int num  = st.top();
        st.pop();
        
        
        reverseStack(st);
        
        insertAtBottom(st,num);
        
    }
};
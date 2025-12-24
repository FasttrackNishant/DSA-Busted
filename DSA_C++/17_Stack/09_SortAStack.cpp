class Solution {
  public:
    void insertSorted(stack<int> &st , int element)
    {
        
        if( st.empty() || st.top() < element)
        {
            st.push(element);
            return ;
        }
        
        
        int num = st.top();
        st.pop();
        
        insertSorted(st,element);
        
        st.push(num);
    }
    
    void sortStack(stack<int> &st) {
    
        if(st.empty())
            return ;
            
        int num = st.top();
        st.pop();
        
        sortStack(st);
         
        insertSorted(st,num);
    }
};

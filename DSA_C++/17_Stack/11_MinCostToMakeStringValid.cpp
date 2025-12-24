#include <bits/stdc++.h> 
int findMinimumCost(string str) {

    int size = str.length();

    if(size % 2 != 0) return -1;

    // remove valid
    stack<char> st;

    for(auto it : str)
    {
      if(it == '{')
      {
        st.push(it);
      }
      else
      {
        if(!st.empty() && st.top() == '{')
        {
          st.pop();
        } 
        else{
          st.push(it);
        }
      }
    }

    int left = 0 ;
    int right = 0;

    while(!st.empty())
    {
      char top = st.top();
      st.pop();

      if(top == '{')
        left++;
      else
        right++;
    }


    int ans = ((left+1)/2) + ((right+1)/2);
    return ans;
    

}
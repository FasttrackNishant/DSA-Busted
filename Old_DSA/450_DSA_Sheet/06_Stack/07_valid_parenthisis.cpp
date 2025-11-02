#include <bits/stdc++.h>
using namespace std;
// =

class Solution {
public:
     bool isValid(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // opening bracket hoga
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                // ya closing bracket hoga

                if (!st.empty())
                {

                    char topCh = st.top();
                    if (ch == ')' && topCh == '(')
                    {
                        // matching brackets
                        st.pop();
                    }
                    else if (ch == '}' && topCh == '{')
                    {

                        st.pop();
                    }
                    else if (ch == ']' && topCh == '[')
                    {

                        st.pop();
                    }
                    else
                    {
                        // brackets not matching1
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
}; 
int main()
{
    int a;
    cout << endl;
    return 0;
}
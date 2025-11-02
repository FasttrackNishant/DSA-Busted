#include <bits/stdc++.h>
using namespace std;
// =

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    // lenght calculate karo
                    int len = i - st.top();
                    maxLength = max(len, maxLength);
                }
            }
        }
        return maxLength;
    }
};
int main()
{
    int a;
    cout << endl;
    return 0;
}
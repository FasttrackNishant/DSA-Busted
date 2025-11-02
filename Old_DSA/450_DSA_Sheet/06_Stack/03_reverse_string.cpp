#include <bits/stdc++.h>
using namespace std;
// =
 int main()
{
    string str = "babbar";
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str.at(i));
    }
    cout << endl;

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
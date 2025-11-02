#include <bits/stdc++.h>
using namespace std;
// =

void printMiddle(stack<int> &st, int &totalSize)
{
    if (st.size() == 0)
    {
        cout << "No element in the Stack " << endl;
    }
    // base case
    if (st.size() == (totalSize / 2) + 1)
    {
        cout << "Middle element is " << st.top() << endl;
        return;
    }

    int temp = st.top();
    st.pop();

    // rr mardo
    printMiddle(st, totalSize);

    // backtrack
    st.push(temp);
}
int main()
{
    stack<int> st;

    st.push(10);
    st.push(40);
    st.push(60);
    st.push(20);
    st.push(15);

    int totalSize = st.size();
    printMiddle(st, totalSize);

    return 0;
}
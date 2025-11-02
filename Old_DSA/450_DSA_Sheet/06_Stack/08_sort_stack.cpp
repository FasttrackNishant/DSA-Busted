#include <bits/stdc++.h>
using namespace std;
// =

void insertSorted(stack<int> &s, int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    // base case
    if (s.top() >= target)
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

    insertSorted(s, target);

    // BT

    s.push(topElement);
}

void sortStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int topElement = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s, topElement);
}

int main()
{
  stack<int> s;
    s.push(5);
    s.push(15);
    s.push(27);
    s.push(32);
    s.push(11);

   
    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    };
    return 0;
}
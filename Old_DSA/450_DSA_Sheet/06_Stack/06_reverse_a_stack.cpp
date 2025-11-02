#include <bits/stdc++.h>
using namespace std;
// =

void insertAtBottom(stack<int> &s, int target)
{
    if (s.empty())
    {

        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();

   // cout << topElement << " " << target << endl;
    insertAtBottom(s, target);
   // cout << endl;
    // Bt
    s.push(topElement);
   // cout<<"topElement "<< topElement<<" "<<endl;
   // cout<<"target "<< target<<" "<<endl;
}

void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    //cout << "targe revers before"<<target << " " << endl;
    //  reverse stack
    reverseStack(s);
    // inser at Bottom target ko

   // cout << "targe revers after" << target << " " << endl;
    insertAtBottom(s, target);
}

int main()
{

    stack<int> s;
    s.push(5);
    s.push(15);
    s.push(27);
    s.push(32);
    s.push(11);

   
    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
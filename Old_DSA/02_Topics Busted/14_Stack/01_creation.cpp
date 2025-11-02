#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // creation

    stack<int> s;

    // push operation

    s.push(2);
    s.push(5);

    // pop
    s.pop();

    cout << "printing top element :- " << s.top() << endl;

    cout << "is stack empty : " << s.empty() << endl;

    cout << "size of the stack is " << s.size() << endl;
 
    return 0;
}
#include <iostream>
using namespace std;

void solve()
{
    //base case

    if(count ==size/2)
    {
        inputstack.pop();
        return;
    }

    int num = inputstack.top();
    inputstack.pop();

}

void deltemid()
{
    int count  =0;
    solve(inputstack, count ,N);
}


int main()
{
    int a;
    cout << endl;
    return 0;
}
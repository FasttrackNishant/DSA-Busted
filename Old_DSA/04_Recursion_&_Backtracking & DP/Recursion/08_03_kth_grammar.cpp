#include <bits/stdc++.h>
using namespace std;

int kthgrammar(int n, int k)
{
    // base case
    if (n == 1)
        return 0;

    int parent = kthgrammar(n - 1, k / 2 + k % 2);

    if (parent == 0)
    {
        if (k & 1)
            return 0;
        else
            return 1;
    }
    else
    {
        if (k & 1)
            return 1;
        else
            return 0;
    }
}
int main()
{
    int a;
    cout << endl;
    return 0;
}
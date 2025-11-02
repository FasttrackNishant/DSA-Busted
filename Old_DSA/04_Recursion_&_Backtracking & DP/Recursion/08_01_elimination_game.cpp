#include <bits/stdc++.h>
using namespace std;

int lastRemaining(int n)
{
    if (n == 1)
        return 1;

    return 2 * (1 + (n / 2) - lastRemaining(n / 2));
}

int main()
{
    int a;
    cout << endl;
    return 0;
}
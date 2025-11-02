/*https://leetcode.com/problems/fibonacci-number/*/

#include <iostream>
using namespace std;

int fibnum(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int ans = fibnum(n - 1) + fibnum(n - 2);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int res = fibnum(n);
    cout << res << endl;
    return 0;
}
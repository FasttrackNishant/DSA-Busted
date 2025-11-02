#include <iostream>
using namespace std;

int factorial(int n)
{

    // base case likhdo
    // if (n == 0)/

        // return 1;

    int small = factorial(n - 1);
    int badi = n * small;
    return badi;


    //or
    // return  n* factorial(n-1);
}
int main()
{
    int a;
    cin >> a;
    int ans = factorial(a);
    cout << ans << endl;
    return 0;
}
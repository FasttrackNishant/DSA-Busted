#include <iostream>
using namespace std;

int subprod(int n)
{
    int sum = 0;
    int prod = 1;
    while (n != 0)
    {
        int digit = n % 10; 
        sum = sum + digit;
        prod = prod * digit;
        n = n / 10;
    }
    int ans = prod - sum;
    return ans;
}

int main()
{
    int n;
    cin >> n;
 cout<<subprod(n);
    
    return 0;
}

// overall idea is hume eisa digit find karna hai jo uske prouct ka aur sum ka difference ho then we just applied remainder trick and then we divided by decimal places
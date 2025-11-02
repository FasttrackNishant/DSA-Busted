#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    int ans = fibonacci(n - 1) + fibonacci(n - 2);

    return ans;
}

int main()
{
    int num;
    cout << "Enter the fibonacci index number" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {

        cout << fibonacci(i) << " ";
    }
    return 0;
}

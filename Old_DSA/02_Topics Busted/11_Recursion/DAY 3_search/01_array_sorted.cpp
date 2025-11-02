#include <iostream>
using namespace std;

bool issorted(int *arr, int n)
{
    if (n == 0 || n == 1)
        return 1;

    if (arr[0] > arr[1])
    {
        return 0;
    }
    else
    {
        // ye remaining part hain..
        bool check = issorted(arr + 1, n - 1);
        return check;
    }

    cout << "function called" << endl;
    return 0;
}

int main()
{
    int arr[] = {4, 5, 6};
    int ans = issorted(arr, 3);
    if (ans)
    {
        cout << "Array is sorted " << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }

    cout << endl;
    return 0;
}
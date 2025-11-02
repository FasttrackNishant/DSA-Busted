#include <iostream>
using namespace std;

int sumofarr(int *arr, int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return arr[0];

    int remaining = sumofarr(arr + 1, n - 1);
    int sum = arr[0] + remaining;
    return sum;
}

int main()
{
    int arr[] = {3, 40, 14, 5, 3};
    int ans = sumofarr(arr, 5);

    cout << "The sum of the array is " << ans << endl;
    return 0;
}
#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    // base case
    if (n == 0 || n == 1)
        return;

    // ek ko bithade
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubblesort(arr, n - 1);
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
int main()
{
    int arr[5] = {7, 3, 15, 20, 14};
    printarr(arr, 5);
    bubblesort(arr, 5);
    printarr(arr, 5);

    cout << endl;
    return 0;
}
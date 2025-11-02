#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    bool swaped = false;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }

            swaped = true;
        }
        if (swaped == false)
        {
            break;
        }
    }
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
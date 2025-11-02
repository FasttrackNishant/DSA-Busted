#include <iostream>
using namespace std;

void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n ; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
                arr[j+1] = arr[j];

            else
                break;
        }
        arr[j + 1] = temp;
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
    int arr[5] = {4, 12, 11, 2, 10};
    printarr(arr, 5);
    insertionsort(arr, 5);
    printarr(arr, 5);

    cout << endl;
    return 0;
}
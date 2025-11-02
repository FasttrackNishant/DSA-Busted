#include <iostream>
using namespace std;

void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionsort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minindex = i;

        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
            swap(arr[minindex], arr[i]);
    }
}

int main()
{
    int arr[] = {11, 3, 2, 24, 64};
    int size = sizeof(arr) / sizeof(int);
    printarr(arr, size);
    selectionsort(arr, size);
    printarr(arr, size);

    cout << endl;
    return 0;
}
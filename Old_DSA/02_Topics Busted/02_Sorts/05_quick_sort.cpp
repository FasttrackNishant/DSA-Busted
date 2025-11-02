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

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int count = 0;

    for (int i = s + 1; i <= e; i++)

    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    // placing pivot at right position
    int pivotIndex = s + count;

    swap(arr[pivotIndex], arr[s]);

    // left  and right waala part sambhale

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
        return pivotIndex;
}

void quicksort(int arr[], int s, int e)
{
    // base case
    // if (size == 0 || size == 1)
    //     r    eturn;
    if (s >= e)
        return;

    // partition karenge

    int p = partition(arr, s, e);

    // left part sort karo

    quicksort(arr, s, p - 1);

    // right wala part sort karo
    quicksort(arr, p + 1, e);
}

int main()
{
    int arr[9] = {11, 3, 2, 24, 64,6,3,9,2};
    int size = sizeof(arr) / sizeof(int);
    int n= 9;
    printarr(arr, size);
    quicksort(arr, 0, n-1);
    printarr(arr, size);

    cout << endl;
    return 0;
}



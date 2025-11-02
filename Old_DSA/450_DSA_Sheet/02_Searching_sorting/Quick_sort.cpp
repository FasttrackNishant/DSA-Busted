#include <bits/stdc++.h>
using namespace std;
// =
void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int s, int e)
{
    int cnt = 0;
    int pivot = arr[s];

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] >= pivot)
            cnt++;
    }
    // first take pivotindex to its proper place

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right handle karyachi aahe
    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] > pivot)
        {
            i++;
        }
        while (arr[j] < pivot)
        {
            j--;
        }

        while (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    // left wala done
    quickSort(arr, s, p - 1);

    // right wala done

    quickSort(arr, p + 1, e);
}
int main()
{
    int arr[] = {5, 2, 8, 4, 9, 3};
    int size = 6;
    int s = 0;
    int e = size - 1;
    printArr(arr, size);
    quickSort(arr, s, e);
    printArr(arr, size);

    return 0;
}
#include <iostream>
using namespace std;

// is method se pura print nahi ho raha divide karte waqt problem aa raha hain at the last stage
void solve(int arr[], int size)
{
    // base case
    if (size < 1)
    {

        return;
    }
    // for loop for printing

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // recursive call
    solve(arr, size / 2);
}

void solvetwo(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        cout << arr[s] << endl;
        return;
    }

    for (int i = s; i <= e; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;

    int mid = (s + e) / 2;

    // recusive call
    solvetwo(arr, s, mid);

    // to print  the right half of the code
    solvetwo(arr, mid + 1, e);
}
void merge(int arr[], int s, int mid, int e)
{
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];

    int *second = new int[len2];

    // copy the values

    int i = 0;
    for (int index = s; index <= mid; index++)
    {
        first[i] = arr[index];
        i++;
    }

    int j = 0;
    for (int index = mid + 1; index <= e; index++)
    {
        second[j] = arr[index];
        j++;
    }

    // merge this two array into original arrays

    int originalArrayIndex = s;
    int index1 = 0;
    int index2 = 0;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[originalArrayIndex] = first[index1];
            index1++;
            originalArrayIndex++;
        }
        else
        {
            arr[originalArrayIndex] = second[index2];
            index2++;
            originalArrayIndex++;
        }
    }

    // exhaust first array

    while (index1 < len1)
    {
        arr[originalArrayIndex] = first[index1];
        index1++;
        originalArrayIndex++;
    }
    // exhaust second array

    while (index2 < len2)
    {
        arr[originalArrayIndex] = second[index2];
        index2++;
        originalArrayIndex++;
    }
}

void mergeSort(int arr[], int s, int e)

{
    // base case
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    // recursino ko sort karne ko do left and right part

    // left part
    mergeSort(arr, s, mid);

    // right wala part
    mergeSort(arr, mid + 1, e);

    // megrge sorted array
    merge(arr, s, mid, e);
}

int main()
{
    int arr[6] = {4, 1, 5, 6, 3, 10};
    int size = 6;
    // solve(arr, size);
    solvetwo(arr, 0, size - 1);
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "Printing the sorted array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
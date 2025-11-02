#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
    // ye function sirf merge karne ke liye hain
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create new arrays

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
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

    // ab in array ko merge karna hai with sorting technique

    int originalArrayIndex = s;
    int index1 = 0;
    int index2 = 0;

    // yaha arrays ki value compare hogi and jo small woh update hogi
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
    // but isme ek problem hoga ki jab array pura traverse nahi hua hain i.e we have to exhaust array

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

    // free the memory taken by dynamic arrays

    delete first;
    delete second;
}

void mergesort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // left wala recursion sambhal lega

    mergesort(arr, s, mid);

    // right wala part rr karlega

    mergesort(arr, mid + 1, e);

    // merge two sorted arrays
    merge(arr, s, mid, e);
}
int main()
{
    int arr[] = {3, 4, 1, 5, 6, 2, 7};
    int size = 7;

    mergesort(arr, 0, size - 1);

    cout << "Printing the sorted array" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}
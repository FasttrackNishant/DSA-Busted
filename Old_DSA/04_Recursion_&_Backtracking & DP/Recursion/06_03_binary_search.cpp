#include <bits/stdc++.h>
using namespace std;

bool binarysearch(int *arr, int s, int e, int target)
{
    // base case
    if (s > e)
        return false;

    int mid = s + (e - s) / 2;

    if (target == arr[mid])
    {
        return true;
    }
    else if (target < arr[mid])
        // search in left
        return binarysearch(arr, s, mid - 1, target);
    else
    { // search in right
        return binarysearch(arr, mid + 1, e, target);
    }
}

int main()
{
    int arr[] = {3, 4, 8};
    int size = 3;

    cout << binarysearch(arr, 0, size - 1, 3);
    cout << endl;
    return 0;
}
#include <iostream>
using namespace std;

void printarr(int *arr, int s, int e)
{

    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool binarysearch(int arr[], int s, int e, int key)
{
    cout << endl;
    printarr(arr, s, e);

    // element not found
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    cout<<"value of arr mid "<<arr[mid]<<endl;
    // element found
    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] < key)
    {
        return binarysearch(arr, mid + 1, e, key);
    }
    else
    {
        return binarysearch(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[6] = {2, 4, 6, 10, 14, 18};
    int size = 6;
    int key = 606;

    cout<<binarysearch(arr, 0, 5, key);
    cout<<endl;
    bool res;
    if (res)

    {
        // cout << "Present";
    }
    else
    {
        //  cout << "Not Present";
    }
    cout << endl;
    return 0;
}
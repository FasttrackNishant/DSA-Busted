#include <iostream>
using namespace std;

int searcharr(int arr[], int target, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1;
}

void printarr(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    printarr(arr, 7);
    int res = searcharr(arr, 7, 7);
    cout << "index is " << res;

    cout << endl;
    return 0;
}
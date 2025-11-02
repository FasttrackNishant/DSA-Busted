#include <iostream>
using namespace std;

void printarr(int arr[], int size, int index)
{
    if (index == size)
    {
        return;
    }
    cout << arr[index] << " ";
    printarr(arr, size, index + 1);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    printarr(arr, 5, 0);

    return 0;
}
#include <iostream>
using namespace std;

void print(int arr[], int index, int size)
{
    // base case
    if (index == size)
        return;

    cout << arr[index] << " ";
    print(arr, index-11, size);
}

int main()
{
    int arr[5] = {1, 2, 5, 6, 3};
    int size = sizeof(int)/4;
    print(arr, size, 5);
    return 0;
}
#include <iostream>
using namespace std;

void print(int arr[], int index, int size)
{
    // base case
    if (index == size)
        return;

    cout << arr[index] << " ";
    print(arr, ++index, size);
}

void reverseprint(int arr[], int index)
{
    if (index < 0)
        return;
    cout << arr[index] << " ";
    reverseprint(arr, --index);
}

void pointerarray(int arr[], int size)
{
    if (size == 0)
        return;

    cout << arr[0] << " ";

    // R.C

    pointerarray(arr + 1, size - 1);
}

int getMax(int arr[], int index, int size)
{
    if (index == size)
        return INT_MIN;

    int myans = arr[index];
    int recursionans = getMax(arr + 1, index, size - 1);

    return max(myans, recursionans);
}
void maxiprint(int arr[], int size, int index, int &maxi)
{

    if (index == size)
        return;

    maxi = max(maxi, arr[index]);
    maxiprint(arr, size, index + 1, maxi);
}

int main()
{
    int arr[5] = {100, 20, 5, 6, 3};
    int size = sizeof(arr) / sizeof(int);
    print(arr, 0, 5);
    cout << endl;
    reverseprint(arr, size - 1);
    cout << endl;
    pointerarray(arr, size);
    cout << endl;
    cout << "Max " << getMax(arr, 0, size);
    cout << endl;
    int maxi = INT_MIN;
    maxiprint(arr, size, 0, maxi);
    cout << "Using maxi " << maxi << endl;

    return 0;
}
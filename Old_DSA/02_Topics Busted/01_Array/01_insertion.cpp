#include <iostream>
using namespace std;
void printarr(int arr[], int size)
{
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " " ;
    }
}

int main()
{
    int arr[100] = {3, 45, 6, 347, 4, 7, 89, 61};
    printarr(arr, 100);
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int getSum(int arr[], int index, int size)
{
    // base case
    if (index == size)
        return 0;

    return arr[index] + getSum(arr, ++index, size);
    
}

int main()
{
    int arr[] = {10,20,30,40,50};
    int size = 5;
    cout << getSum(arr, 0, size);
    cout << endl;
    return 0;
}
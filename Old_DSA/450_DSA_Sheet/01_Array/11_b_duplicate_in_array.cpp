/*
time complexity - O(n)
space complexity - O(n)*/


#include <iostream>
using namespace std;

void duplicate(int arr[], int n)
{
    int a[n] = {0};

for (int i = 0; i < n; i++)
{
    a[arr[i]]++;

}
for (int i = 0; i < n; i++)
{
    if(a[i]>1)
    cout<<i;
}

}

int main()
{
    int arr[6] = {1, 3, 4, 5,3, 4};

    duplicate(arr, 6);
    return 0;
}
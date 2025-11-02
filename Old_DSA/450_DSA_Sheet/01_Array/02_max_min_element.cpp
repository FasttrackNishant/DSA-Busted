#include <bits/stdc++.h>
using namespace std;

int main()
{
int arr[]={9,4,6,2,1};
int size = sizeof(arr)/4;
sort(arr, arr+size);

for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
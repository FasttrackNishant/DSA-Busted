#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x=8;
    int arr[] = {5,7,7,8,8,10};
    int size = sizeof(arr) / 4;
    sort(arr, arr + 5);
    int first = -1;
    int last = -1;
    for (int i = 0; i < size; i++)
    {
        if (x!= arr[i])
        {
            continue;
        }
        if (first == -1)
        {
            first = i;
        }
        last = i;
    }
    if (first != -1)
    {
        cout << first << " " << last;
    }
    else
    {
        cout << "-1"<<"-1";
    }
    return 0;
}
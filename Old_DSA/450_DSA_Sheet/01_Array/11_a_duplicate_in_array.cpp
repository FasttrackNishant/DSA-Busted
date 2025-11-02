#include <bits/stdc++.h>
using namespace std;

void sortarr(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        swap(arr[minindex], arr[i]);
    }
}

int duplicate(int arr[], int n)
{
    sortarr(arr, 5);
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {

            vec.push_back(arr[i]);
        }
    }

    for(auto it :vec) 
    {
        cout<<it<<" ";
    }
}

int main()
{
    int arr[5] = {1, 3, 4, 2, 2};

duplicate(arr, 5);
    return 0;
}
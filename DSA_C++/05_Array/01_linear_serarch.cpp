#include <bits/stdc++.h>
using namespace std;

void linearsearch(int *arr, int n, int key)
{
    bool flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            flag = 1;
        }

        if (flag)
            cout << "Element found " << endl;
        else
            cout << "Element not found " << endl;
    }
}
int main()
{
    int arr[10] = {2, 5, 6, 8, 16, 12, 20};
    linearsearch(arr, 7, 16);

    return 0;
}
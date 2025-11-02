#include <bits/stdc++.h>
using namespace std;

int solve(int i, int arr[], int diff)
{
    // backward check kar rahe hain

    if (i < 0)
        return 0; // piche koi element exist hi nahi karta

    int ans = 0;
    for (int k = i - 1; k >= 0; k--)
    {
        if (arr[i] - arr[k] == diff)
        { // number found in ap

            ans = max(ans, 1 + solve(k, arr, diff));
        }
    }
    return ans;
}

int main()
{
    int arr[] = {9, 4, 7, 2, 10};
    int size = 5;

    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        { // notice to add 2 for two elements given by two loops
            int diff = arr[j] - arr[i];
            ans = max(ans, 2 + solve(i, arr, diff));
        }
    }
    cout << "Printing ans " << ans << endl;

    cout << endl;
    return 0;
}
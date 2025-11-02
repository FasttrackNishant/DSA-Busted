#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solveSubArraySum(int arr[], int size, int k)
{
    vector<int> result;
    int maxi = 0;

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];

            if (sum == k)
            {
                maxi = max(maxi,j-i+1);
            }
        } 
    }

    return maxi;
}
int main()
{
    int arr[] = {1, 2, 3,0,0,1, 1, 1, 1, 4, 2, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "(";
            for (int k = i; k <= j; k++)
            {
                cout << arr[k];
                if (k < j)
                    cout << ", ";
            }
            cout << ")" << endl;
        }
    }

    cout << solveSubArraySum(arr, n, 3) << endl;

    return 0;
}
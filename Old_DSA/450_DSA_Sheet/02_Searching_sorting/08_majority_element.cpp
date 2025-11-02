/*https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1*/

// { Driver Code Starts
// Initial Template for C

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        unordered_set<int> s;
        int count, max;
       count =max=0;

        for (int ir = 0; ir < size; ir++)
        {
            if (s.find(a[ir]) == s.end())
            {
                s.insert(a[ir]);
            }
        }
        // for (auto it : s)
        // {
        //     cout << it << " ";
        // }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << "inloop"<<endl;
                count++;
            }
            if (count > max)
            {
                cout << "in if"<<endl;
                max = count;
            }
        }
        cout << count;
        cout << max;
    }
};
// { Driver Code Starts.

int main()
{

    int n = 5;

    int arr[5] = {3, 1, 3, 3, 2};

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    Solution obj;
    obj.majorityElement(arr, n);

    return 0;
}

// } Driver Code Ends
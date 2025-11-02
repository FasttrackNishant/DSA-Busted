#include <iostream>
using namespace std;

int longestSubarray1(vector<int> arr, int k)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
                sum += arr[k];
            }
            cout << endl;

            if (sum == k)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }

    return ans;
}

int longestSubarray2(vector<int> arr, int k)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = arr[i];
        for (int j = i+1; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }

    return ans;
}

int longestSubarrayPrefixSum(vector<int> arr , long long k )
{
    unordered_map<int,int> preSumMap;
    long long sum =0;
    int maxLen =0;
    for(int i =0 ; i < arr.size() ;i++)
    {
        sum += arr[i];
        if(sum == k )
        {
            maxLen = max(maxLen,i+1);
        }

        long long rem = sum - k ;
        if(preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }

        preSumMap[sum] =  i;

    }
    return maxLen;
}

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    cout << longestSubarray2(arr, 15);
    return 0;
}
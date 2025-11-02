#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> calculateSum(vector<int> arr)
    {
        vector<int> ans;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            int tempSum = 0;
            for(int j = i ; j < arr.size() ; j++)
            { 
                tempSum += arr[j];
                ans.push_back(tempSum);
            }
        }
        return ans;
    }
    
    int kthLargest(vector<int> &arr, int k) {
        
        auto subArraySum = calculateSum(arr);
        
        sort(subArraySum.begin(),subArraySum.end());
      
        int size = subArraySum.size();
        
        return subArraySum[size-k];
        
    }
};
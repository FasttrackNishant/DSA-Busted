#include <iostream>
#include <vector>
using namespace std;

void maximumSubarray(vector<int> nums)
{
    long long ans = INT_MIN;
    int sum =0; 
    int start = 0 ;
    int ansStart = 0 ;
    int ansEnd = 0;

    for(int i =0 ; i < nums.size() ; i++)
    {
        if(sum ==0) start = i;
        sum += nums[i];

        if(sum > ans)
        {
            ans = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0)
        {
            sum =0;
        }

    }
    cout << ansStart << " " << ansEnd;
}

int main() {

    vector<int> nums = {5,4,-1,7,8};
    maximumSubarray(nums);
    
    return 0;
}
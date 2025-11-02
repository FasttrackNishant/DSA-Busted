#include <iostream>
#include "printVector.hpp"
using namespace std;

void insertionSortAsc(vector<int> &nums)
{
    int n = nums.size();
    for(int i = 1 ; i < n ; i++)
    {
        int key = nums[i];
        int j = i-1;
        while(j>=0)
        {
            if(nums[j] > key)
            {
                nums[j+1] = nums[j];
                j--;
            }
            else{
                break;
            }
        }
        nums[j + 1] = key;
    }
}

int main() {
    
     vector<int> nums = {23,12,43,5,8,33};
     insertionSortAsc(nums);
     printVectorFun(nums);
    return 0;
}
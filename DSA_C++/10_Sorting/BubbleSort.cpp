#include <iostream>
#include "printVector.hpp"
using namespace std;

void bubbleSortAsc(vector<int> &nums)
{
   int n = nums.size();
bool isSwapped = false;
   for(int i =0 ; i < n - i ; i++)
   {
       for (int j = 0; j < n - i - 1; j++)
       {
           if (nums[j] > nums[j + 1])
           {
               isSwapped = true;
               swap(nums[j], nums[j + 1]);
           }
       }
       if (!isSwapped)
           break;
   }
}

int main() {
    
     vector<int> nums = {23,12,43,5,8,33};
     bubbleSortAsc(nums);
     printVectorFun(nums);

     return 0;
}
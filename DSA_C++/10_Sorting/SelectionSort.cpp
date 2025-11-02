#include <iostream>
#include "printVector.hpp"
using namespace std;

void selectionSortAsc(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

void selectionSortDesc(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(nums[j] > nums[minIndex])
            {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

int main() {
    vector<int> nums = {23,12,43,5,8,33};

    selectionSortAsc(nums);
    printVectorFun(nums);

    selectionSortDesc(nums);
    cout << endl;
    printVectorFun(nums);

    return 0;
}
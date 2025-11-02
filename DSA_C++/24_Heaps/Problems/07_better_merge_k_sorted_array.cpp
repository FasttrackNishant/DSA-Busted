#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeTwoArrays(vector<int> &first, vector<int> &second)
    {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < first.size() && j < second.size())
        {
            if (first[i] < second[j])
            {
                ans.push_back(first[i++]);
            }
            else
            {
                ans.push_back(second[j++]);
            }
        }

        // aga kuch bach gaya hoga

        while (i < first.size())
            ans.push_back(first[i++]);

        while (j < second.size())
            ans.push_back(second[j++]);

        return ans;
    }

    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {

        vector<int> result;

        for (int i = 0; i < K; i++)
        {
            result = mergeTwoArrays(result, arr[i]);
        }

        return result;
    }
};

int main()
{

    return 0;
}
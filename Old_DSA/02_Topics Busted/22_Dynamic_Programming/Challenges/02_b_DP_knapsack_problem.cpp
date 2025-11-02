#include <bits/stdc++.h>
using namespace std;

int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> dp +)
{

    // base case
    /*this conditon is for only if single item is present then add kare ya na kare it  depenes on the the capacity lift in the bag*/
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        // ab yaha element include ho gayya and recursive call gayi next ke liye
        include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
    }

    int exclude = 0 + solveMem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(exclude, include);

    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    // step 1 create dp array

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    return solveMem(weight, value, n - 1, maxWeight, dp);
}

int main()
{

    return 0;
}
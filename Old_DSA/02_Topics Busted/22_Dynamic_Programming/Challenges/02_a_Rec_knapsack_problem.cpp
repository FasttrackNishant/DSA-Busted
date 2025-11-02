#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
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
    int include = 0;
    if (weight[index] <= capacity)
    {
        // ab yaha element include ho gayya and recursive call gayi next ke liye
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    }

    int exclude = 0 + solve(weight, value, index - 1, capacity);

    int ans = max(exclude, include);

    return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    return solve(weight, value, n - 1, maxWeight);
}

int main()
{
    int a;
    cout << endl;
    return 0;
}
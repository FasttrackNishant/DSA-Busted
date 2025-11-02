#include <bits/stdc++.h>
using namespace std;
// =

int solve(vector<int> val, vector<int> wt, int index, int capacity)
{
    // base case

    if (index == val.size() || capacity == 0)
        return 0;

    int include = 0;

    if (capacity >= wt[index])
    {
        include = val[index] + solve(val, wt, index + 1, capacity - wt[index]);
    }

    int exclude = 0 + solve(val, wt, index + 1, capacity);

    return max(include, exclude);
}

int main()
{
    vector<int> val, wt;

    val.push_back(60);
    val.push_back(100);
    val.push_back(120);

    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);

    int capacity = 50;


    int ans = solve(val, wt, 0, capacity);
    cout << ans << endl;
    return 0;
}
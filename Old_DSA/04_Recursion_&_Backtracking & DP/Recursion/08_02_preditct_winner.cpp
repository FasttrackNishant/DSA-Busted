#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &num, int i, int j)
{
    if (i > j)
        return 0;

    if (i == j)
        return num[i];

    int option1 = num[i] + min(solve(num, i + 2, j), solve(num, i + 1, j - 1));x
    int option2 = num[j] + min(solve(num, i, j - 2), solve(num, i + 1, j - 1));

    return max(option1, option2);
}

bool predictWinner(vector<int> &nums)
{

    int p1_score = solve(nums, 0, nums.size() - 1);
    int totalscore = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        totalscore += nums[i];
    }
    int p2_score = totalscore - p1_score;

    if (p1_score >= p2_score)
        return true;
    else
        return false;
}

int main()
{
    int a;
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// =

class Solution
{
public:
    void solve(vector<string> &ans, int n, int open, int close, int rem_open, int rem_close, string output)
    {

        // base case
        if (rem_open == 0 && rem_close == 0)
        {
            ans.push_back(output);
            return;
        }

        // include open bracket

        if (rem_open > 0)
        {
            output.push_back('(');
            solve(ans, n, open + 1, close, rem_open - 1, rem_close, output);
            // backtrack

            output.pop_back();
        }

        // include close bracket

        if (open > close)
        {
            output.push_back(')');
            solve(ans, n, open, close + 1, rem_open, rem_close - 1, output);
            // backtrack
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int open = n;
        int close = n;
        int rem_open = n;
        int rem_close = n;
        string output = "";
        solve(n, open, close, rem_open, rem_close, output);
        return ans;
    }
};

int main()
{
    int a;
    cout << endl;
    return 0;
}
class Solution
{
public:
    void solve(vector<string> &ans, int n, int open, int close, int rem_open, int rem_close, string output)
    {

        // base case
        if (rem_open == 0 && rem_close == 0)
        {
            ans.push_back(output);
            return;
        }

        // include open bracket

        if (rem_open > 0)
        {
            output.push_back('(');
            solve(ans, n, open + 1, close, rem_open - 1, rem_close, output);
            // backtrack

            output.pop_back();
        }

        // include close bracket

        if (open > close)
        {
            output.push_back(')');
            solve(ans, n, open, close + 1, rem_open, rem_close - 1, output);
            // backtrack
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int open = n;
        int close = n;
        int rem_open = n;
        int rem_close = n;
        string output = "";
        solve(n, open, close, rem_open, rem_close, output);
        return ans;
    }
};

int main()
{
    int a;
    cout << endl;
    return 0;
}
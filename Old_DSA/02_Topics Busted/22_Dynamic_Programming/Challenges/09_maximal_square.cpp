#include <bits/stdc++.h>
using namespace std;
// =

int solve(vector<vector<char>> &matrix, int i, int j, int maxi)
{
    // base case
    if (i > matrix.size() || j >= matrix[0].size())
    {
        return 0;
    }
    int bottom = solve(matrix, i + 1, j,maxi);
    int diagonal = solve(matrix, i + 1, j + 1,maxi);
    int right = solve(matrix, i, j + 1,maxi);

    if (matrix[i][j] == '1')
    {
        int side =  min(bottom, min(right, diagonal)) + 1;
        maxi = max(maxi , side);
        return side; 
    }
    else
    {
        return 0;
    }
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int ans = solve(matrix, 0, 0, maxi);

    return maxi * maxi;
}
int main()
{
    int a;
    cout << endl;
    return 0;
}
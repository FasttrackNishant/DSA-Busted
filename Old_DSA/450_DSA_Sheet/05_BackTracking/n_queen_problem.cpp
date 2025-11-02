#include <bits/stdc++.h>
using namespace std;
// =

class Solution
{
public:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        // check straight movement
        int x = row;
        int y = col;

        while (y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }
            y--;
        }

        // upper diagonal movement

        x = row;
        y = col;

        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        // lower diagonal
        x = row;
        y = col;

        while (x <= n && y >= 0)
        {
            if (board[x][y] == 'Q')

            {
                return false;
            }
            x++;
            y--;
        }
        // agr kuch nahi hain toh true retur karo
        return true;
    }

    void solve(vector<string> &board, vector<vector<string>> &ans, int n, int col)
    {
        if (col == n)
        {
            // store the ans
            ans.push_back(board);
            // return
            return;
        }

        // ek case solve karo

        for (int row = 0; row < n; row++)
        {
            if (isSafe(board, row, col, n))
            {
                // action
                board[row][col] = 'Q';
                // rr
                solve(board, ans, n, col + 1);

                // backtring logic
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        // board
        vector<string> board(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i] = '.';
            }
        }

        vector<vector<string>> ans;
        int col = 0;
        solve(board, ans, n, col);
    }
};
int main()
{
    int a;
    cout << endl;
    return 0;
}
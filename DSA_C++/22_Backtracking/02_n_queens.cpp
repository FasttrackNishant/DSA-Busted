#include <iostream>
#include <vector>
using namespace std;


void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp); // FIXED
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) // FIXED: Pass by reference
{
    // check left row
    int x = row, y = col;
    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    // check left-top diagonal
    x = row, y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check left-bottom diagonal
    x = row, y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true; // FIXED
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0; // backtrack
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> res = nQueens(n);

    for (auto sol : res)
    {
        for (int i = 0; i < sol.size(); i++)
        {
            cout << sol[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
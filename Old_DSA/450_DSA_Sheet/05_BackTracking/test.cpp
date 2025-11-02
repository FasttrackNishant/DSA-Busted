class Solution
{
public:
    bool isSafe(int k, int row, int col, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            // row check
            if (board[row][i] == k + '0')
                return false;

            // col check
            if (board[i][col] == k + '0')
                return false;

            // 3*3 sub m,atrix check
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == k + '0')
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                // empty cell
                if (board[row][col] == '.')
                {

                    for (int k = 1; k <= 9; k++)
                    {
                        if (isSafe(k, row, col, board))
                        {
                            board[row][col] = k + '0';
                            bool aageKaSolution = solve(board);
                            if (aageKaSolution == true)
                            {
                                return true;
                            }
                            else
                            {
                                // backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
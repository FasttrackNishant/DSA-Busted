class Solution
{
public:
    bool isSafe(int num, int row, int col, vector<vector<char>> &board)
    {

        for (int i = 0; i < 9; i++)
        {
            // row check
            if (board[row][i] == k)
                return false;

            // col check

            if (board[i][col] == k)
                return false;

            // 3 x 3 matrix check karna hain

            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == k)
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
                // empty hain to hi aage jao
                if (board[row][col] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (isSafe(k, row, col, board))
                        { // action
                            board[row][col] = k + '0';

                            // rr call
                            bool aagekaSoln = solve(board);

                            if (aagekaSoln==true)
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
    }

    void solveSudoku(vector<vector<char>> &board)
    {
    }
};
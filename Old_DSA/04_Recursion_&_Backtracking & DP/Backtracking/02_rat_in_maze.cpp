#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &visited)
{
    int rowSize = board.size();
    int colSize = board[0].size();

    if ((x >= 0 && x < rowSize) && (y >= 0 && y < colSize) && (visited[x][y] == false) && (board[x][y] == '.'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool solve(int srcx, int srcy, int destx, int desty, vector<vector<char>> &board, vector<vector<bool>> &visited, string output)
{

    // base case
    if (srcx == destx && srcy == desty)
    {
        cout << "path is " << output << endl;
        return true;
    }

    // down
    // movement check karo
    int newx = srcx + 1;
    int newy = srcy;
    bool downAns = false;

    if (isSafe(newx, newy, board, visited))
    {
        visited[newx][newy] = true;
        downAns = solve(newx, newy, destx, desty, board, visited, output + 'D');
        // backtrack
        visited[newx][newy] = false;
    }

    // Right

    // movement check karo
    newx = srcx;
    newy = srcy + 1;
    bool rightAns = false;

    if (isSafe(newx, newy, board, visited))
    {
        visited[newx][newy] = true;
        rightAns = solve(newx, newy, destx, desty, board, visited, output + 'R');
        // backtrack
        visited[newx][newy] = false;
    }

    // Left
    //  movement check karo
    newx = srcx;
    newy = srcy - 1;
    bool leftAns = false;

    if (isSafe(newx, newy, board, visited))
    {
        visited[newx][newy] = true;
        leftAns = solve(newx, newy, destx, desty, board, visited, output + 'L');
        // backtrack
        visited[newx][newy] = false;
    }

    // up
    //  movement check karo
    newx = srcx - 1;
    newy = srcy;
    bool upAns = false;

    if (isSafe(newx, newy, board, visited))
    {
        visited[newx][newy] = true;
        upAns = solve(newx, newy, destx, desty, board, visited, output + 'U');
        // backtrack
        visited[newx][newy] = false;
    }

    if (downAns || rightAns || leftAns || upAns)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int srcx = 0;
    int srcy = 0;
    int destx = 3;
    int desty = 3;

    // ab board banann hain

    vector<vector<char>> board(4, vector<char>(4, '.'));
    board[0][3] = '*';
    board[1][1] = '*';
    // board[2][1] = '*';
    board[1][2] = '*';
    board[3][1] = '*';

    vector<vector<bool>> visited(4, vector<bool>(4, false));
    visited[0][0] = true;

    cout << "printing the  board" << endl;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Printing the visited array " << endl;
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[i].size(); j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    // path bhi print karde

    string output = "";

    bool ans = solve(srcx, srcy, destx, desty, board, visited, output);
    cout << "src to destination is possible or not " << ans << endl;
    return 0;
}

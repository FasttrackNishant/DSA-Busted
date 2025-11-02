#include <iostream>
using namespace std;

class Solution {
  public:
      bool isSafe(int x, int y , vector<vector<bool>> &visited , vector<vector<int>> arr , int n)
      {
          if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1)
              return true;
          else
              return false;
      }

      void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
      {
        //base case
        if(x==n-1 && y == n-1)
        {
            ans.push_back(path); 
            return ;
        }

        // 4 movement
        // D , L , R , U

        visited[x][y] = 1;
        // Down
        if (isSafe(x + 1, y, visited, arr, n))
        {
            solve(x + 1, y, arr, n, ans, visited , path + 'D');
        }
        
        // Left
        if(isSafe(x,y-1,visited,arr,n))
        {
            solve(x,y-1,arr,n,ans,visited,path+'L');
        }
        
        // right
        if(isSafe(x,y+1,visited,arr,n))
        {
            solve(x,y+1,arr,n,ans,visited,path+'R');
        }
        
        // Up
        if(isSafe(x-1,y,visited,arr,n))
        {
            solve(x-1,y,arr,n,ans,visited,path+'U');
        }

        visited[x][y] = 0;
        
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze,int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        string path = "";

        if(maze[0][0]==0)
        {
            return ans;
        }
        solve(0, 0, maze, n, ans, visited, path);

        return ans;
    }
};

int main() {

    Solution s1;

    // s1.ratInMaze()
    
    return 0;
}
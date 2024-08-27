#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
    
int f(int i, int j, int rows, int cols, vector<vector<int>>& Grid) {
    if(i >= rows or j >= cols) return INT_MAX;
    else if(i==rows-1 and j ==cols-1) return Grid[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int minCost = INT_MAX;
    minCost = Grid[i][j] + min(f(i+1,j,rows,cols,Grid), f(i,j+1,rows,cols,Grid));

    return dp[i][j] = minCost;
}
int minPathSum(vector<vector<int>>& grid) {
    int rows=grid.size();
    int cols=grid[0].size();
    dp.clear();
    dp.resize(rows,vector<int>(cols,-1));
    int ans = f(0,0,rows,cols,grid);
    return ans;
}

int main() {
    vector<vector<int>> Grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    int answer = minPathSum(Grid);

    cout << answer << endl;
}

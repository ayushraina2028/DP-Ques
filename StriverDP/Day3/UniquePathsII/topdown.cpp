#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
    
int f(int i, int j, int rows, int cols, vector<vector<int>>& Grid) {
    if(i==rows-1 and j==cols-1) {
        return 1;
    }
    else if(i >= rows or j >= cols or Grid[i][j] == 1) {
        return 0;
    }
    
    // check for solved sub problem
    if(dp[i][j] != -1) return dp[i][j];
    
    long long int answer = f(i+1,j,rows,cols,Grid) + f(i,j+1,rows,cols,Grid);
    return dp[i][j] = answer;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows=obstacleGrid.size();
    int cols=obstacleGrid[0].size();        
    
    if(obstacleGrid[rows-1][cols-1] == 1) return 0;
    
    dp.clear();
    dp.resize(rows);
    
    for(int i = 0;i < rows; i++) {
        dp[i].resize(cols,-1);
    }
    return f(0,0,rows,cols,obstacleGrid);
}

int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};
    int answer = uniquePathsWithObstacles(obstacleGrid);

    cout << answer << endl;
}

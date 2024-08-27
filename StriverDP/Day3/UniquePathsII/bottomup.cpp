#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();

    vector<vector<long long int>> dp(rows+1,vector<long long int>(cols+1,0));

    // Base Case
    dp[rows-1][cols-1]=1;
    if(obstacleGrid[rows-1][cols-1] == 1) return 0;

    for(int i = rows-1;i >= 0;i--) {
        for(int j = cols-1; j >= 0; j--) {

            if(i==rows-1 and j==cols-1) continue;
            else if(obstacleGrid[i][j] == 1) continue;

            dp[i][j] = dp[i+1][j] + dp[i][j+1];

        }
    }

    return dp[0][0];
}

int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};
    int answer = uniquePathsWithObstacles(obstacleGrid);

    cout << answer << endl;
}
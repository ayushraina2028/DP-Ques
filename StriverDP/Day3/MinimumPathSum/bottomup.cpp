#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int rows=grid.size();
    int cols=grid[0].size();
    
    vector<vector<int>> dp(rows+1,vector<int>(cols+1,1e9));

    // Base Case
    for(int k = cols; k >= 0; k--) {
        if(k==cols-1) dp[rows-1][k] = grid[rows-1][k];
        else dp[rows-1][k] = grid[rows-1][k] + dp[rows-1][k+1];
    }

    // Looping
    for(int i = rows-2; i >= 0; i--) {
        for(int j = cols-1; j >= 0; j--) {

            dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);

        }
    }

    return dp[0][0];
}

int main() {
    vector<vector<int>> Grid = {{1,2,3}, {4,5,6}};
    int answer = minPathSum(Grid);

    cout << answer << endl;
}
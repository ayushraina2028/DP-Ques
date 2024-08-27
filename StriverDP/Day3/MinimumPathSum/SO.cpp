#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int rows=grid.size();
    int cols=grid[0].size();
    
    vector<int> dp(cols+1,1e9);

    // Base Case
    for(int k = cols-1; k >= 0; k--) {
        if(k==cols-1) dp[k] = grid[rows-1][k];
        else dp[k] = grid[rows-1][k] + dp[k+1];
    }

    // Looping
    for(int i = rows-2; i >= 0; i--) {

        vector<int> curr(cols+1,1e9);

        for(int j = cols-1; j >= 0; j--) {
            curr[j] = grid[i][j] + min(dp[j], curr[j+1]);
        }

        dp = curr;
    }

    return dp[0];
}

int main() {
    vector<vector<int>> Grid = {{1,2,3}, {4,5,6}};
    int answer = minPathSum(Grid);

    cout << answer << endl;
}
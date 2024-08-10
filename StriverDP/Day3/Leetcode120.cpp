#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i,int j,int rows,vector<vector<int>>& Grid) {
    
    int cols=rows+1;
    if(i >= rows or j >= cols) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int minCost=INT_MAX;
    minCost = Grid[i][j] + min(f(i+1,j,rows,Grid), f(i+1,j+1,rows,Grid));

    return dp[i][j] = minCost;
}

int main() {
    vector<vector<int>> matrix = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int rows = matrix.size();

    dp.clear();
    dp.resize(rows);

    for(int i = 0;i < rows; i++) {
        dp[i].resize(i+2,-1);
    }

    int ans = f(0,0,rows,matrix);
    cout << ans << endl;
}
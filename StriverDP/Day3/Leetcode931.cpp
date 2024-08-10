#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i,int j,int rows,int cols,vector<vector<int>>& Grid) {
    
    if(i >= rows or j >= cols) return 0;
    else if(dp[i][j] != -2) return dp[i][j];

    int minCost=INT_MAX;
    if(j==0) {
        minCost = Grid[i][j] + min(f(i+1,j,rows,cols,Grid), f(i+1,j+1,rows,cols,Grid));
    }
    else if(j==cols-1) {
        minCost = Grid[i][j] + min(f(i+1,j,rows,cols,Grid), f(i+1,j-1,rows,cols,Grid));
    }
    else {
        minCost = Grid[i][j] + min(f(i+1,j-1,rows,cols,Grid), min(f(i+1,j,rows,cols,Grid), f(i+1,j+1,rows,cols,Grid)));
    }
    
    dp[i][j] = minCost;
    return minCost;
}

int main() {
    vector<vector<int>> matrix = {{-19,57},{-40,-5}};
    
    int rows=matrix.size();
    int cols=matrix[0].size();

    dp.clear();
    dp.resize(rows,vector<int>(cols,-2));


    int minCost = INT_MAX;
    for(int i = 0;i < cols; i++) {
        minCost = min(minCost,f(0,i,rows,cols,matrix));
    }
    cout << minCost << endl;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;


int f(int i, int j, int rows, int cols, vector<vector<int>>& Grid) {
    if(i >= rows or j >= cols) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int maxCost=INT_MIN;
    for(int x=0;x<cols;x++) {
        if(x==j) continue;
        maxCost = max(maxCost, Grid[i][j] + f(i+1,x,rows,cols,Grid));
    }

    return dp[i][j] = maxCost;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> Grid(N, vector<int>(3,-1));
    for(int i = 0;i < N; i++) {
        cin >> Grid[i][0] >> Grid[i][1] >> Grid[i][2];
    }

    int maxCost=Grid[0][0];

    dp.clear();
    dp.resize(N, vector<int>(3,-1));

    for(int i = 0;i < 3; i++) {
        maxCost=max(maxCost, f(0,i,N,3,Grid));
    }

    cout << maxCost << endl;
}
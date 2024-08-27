#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
    
int f(int i, int j, int m, int n) {
    // if we reach last row/col then 1 way is there
    if(i == m-1 or j == n-1) return 1;
    else if(dp[i][j] != -1) return dp[i][j];
    
    return dp[i][j] = f(i+1,j,m,n) + f(i,j+1,m,n);
}
int uniquePaths(int m, int n) {
    
    dp.clear();
    dp.resize(m, vector<int>(n,-1));
    
    return f(0,0,m,n);
}

int main() {
    int m = 3, n= 7;
    cout << uniquePaths(m,n) << endl;
}

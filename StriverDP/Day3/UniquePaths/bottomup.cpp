#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    if(n==1 or m==1) return 1;

    // Base Cases
    dp[m-1][n-1] = 1;
    
    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {

            // Dont check Base Cases
            if(i==m-1 and j==n-1) continue;
            dp[i][j] = dp[i+1][j] + dp[i][j+1];

        }
    }

    for(auto row : dp) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }

    return dp[0][0];
}

int main() {
    int m = 3, n= 7;
    cout << uniquePaths(m,n) << endl;
}
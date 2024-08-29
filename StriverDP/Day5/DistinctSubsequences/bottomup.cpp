#include <bits/stdc++.h>
using namespace std;

int numDistinct(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

    for(int i = 0;i <= n; i++) dp[i][m] = 1;

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            
            if(a[i]==b[j]) dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
            else dp[i][j] = dp[i+1][j];

        }
    }

    return dp[0][0];
}

int main() {
    string a = "babgbag";
    string b = "bag";

    int ans = numDistinct(a,b);
    cout << ans << endl;
}
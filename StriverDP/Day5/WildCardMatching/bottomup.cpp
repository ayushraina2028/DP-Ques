#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    // Base Cases
    dp[n][m]=1;
    for(int k = m-1;k >= 0; k--) {
        if(p[k] == '*') dp[n][k] = 1;
        else break;
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {

            if(s[i]==p[j] or p[j] == '?') dp[i][j] = dp[i+1][j+1];
            else if(p[j] == '*') dp[i][j] = dp[i+1][j] || dp[i][j+1];

        }
    }

    return dp[0][0];
}

int main() {
    string s = "cb";
    string p = "?b";

    bool ans = isMatch(s,p);
    cout << ans << endl;    
}

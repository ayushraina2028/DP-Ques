#include <bits/stdc++.h>
using namespace std;

int minDistance(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {

            if(text1[i]==text2[j]) dp[i][j] += 1 + dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);

        }
    }

    int lcsLen = dp[0][0];
    if(n==m) return 2*(n-lcsLen);
    
    if(n > m) {
        if(m==0) return n+m;
        else return 2*(m-lcsLen) + 1*(n-m);
    }

    return 2*(n-lcsLen) + 1*(m-n);
    
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    int ans = minDistance(s1,s2);
    cout << ans << endl;
}

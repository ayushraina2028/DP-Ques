#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int LCS(int i, int j, int n, int m, string& p, string& q) {

    if(i==n or j==m) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int maxLen = 0;
    if(p[i] == q[j]) maxLen = 1 + LCS(i+1,j+1,n,m,p,q);
    else maxLen = max(LCS(i+1,j,n,m,p,q),LCS(i,j+1,n,m,p,q));

    return dp[i][j] = maxLen;

}

int longestCommonSubsequence(string text1, string text2) {
    
    int n = text1.length();
    int m = text2.length();

    dp.clear();
    dp.resize(n+1,vector<int>(m+1,-1));

    int len = LCS(0,0,n,m,text1,text2);
    return len;
}

int main() {
    string a = "abcdgh";
    string b = "acdghr";

    int ans = longestCommonSubsequence(a,b);
    cout << ans << endl;
}

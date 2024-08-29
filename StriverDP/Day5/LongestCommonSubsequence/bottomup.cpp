#include <bits/stdc++.h>
using namespace std;


int longestCommonSubsequence(string text1, string text2) {
    
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {

            if(text1[i]==text2[j]) dp[i][j] += 1 + dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);

        }
    }

    // print dp
    for(auto x : dp) {
        for(auto y : x) cout << y << " ";
        cout << endl;
    }

    return dp[0][0];
}

int main() {
    string a = "abcdgh";
    string b = "acdghr";

    int ans = longestCommonSubsequence(a,b);
    cout << ans << endl;
}

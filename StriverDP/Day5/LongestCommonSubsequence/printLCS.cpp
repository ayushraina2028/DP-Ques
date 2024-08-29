#include <bits/stdc++.h>
using namespace std;


string longestCommonSubsequence(string text1, string text2) {
    
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {

            if(text1[i]==text2[j]) dp[i][j] += 1 + dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);

        }
    }

    // for(auto x : dp) {
    //     for(auto y : x) cout << y << " ";
    //     cout << endl;
    // }

    string ans = "";
    
    int i = 0;
    int j = 0;

    while(i < n and j < m) {
        if(text1[i] == text2[j]) {
            ans += text1[i];
            i++;
            j++;
        }

        else if(dp[i][j+1] > dp[i+1][j]) j++;
        else i++;
    }

    return ans;
}

int main() {
    string a;
    string b;

    cin >> a >> b;

    string ans = longestCommonSubsequence(a,b);
    cout << ans << endl;
}

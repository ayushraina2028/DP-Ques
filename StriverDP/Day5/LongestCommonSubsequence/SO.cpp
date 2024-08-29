#include <bits/stdc++.h>
using namespace std;


int longestCommonSubsequence(string text1, string text2) {
    
    int n = text1.length();
    int m = text2.length();

    vector<int> dp(m+1,0);

    for(int i = n-1; i >= 0; i--) {

        vector<int> curr(m+1,0);

        for(int j = m-1; j >= 0; j--) {

            if(text1[i]==text2[j]) curr[j] += 1 + dp[j+1];
            else curr[j] = max(dp[j], curr[j+1]);

        }

        dp = curr;
    }

    return dp[0];
}

int main() {
    string a = "abcdgh";
    string b = "acdghr";

    int ans = longestCommonSubsequence(a,b);
    cout << ans << endl;
}

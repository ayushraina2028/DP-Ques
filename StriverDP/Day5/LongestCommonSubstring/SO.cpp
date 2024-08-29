#include <bits/stdc++.h>
using namespace std;


int longestCommonSubtring(string text1, string text2) {
    
    int n = text1.length();
    int m = text2.length();

    vector<int> dp(m+1,0);
    int maxLen = 0;

    for(int i = n-1; i >= 0; i--) {

        vector<int> curr(m+1,0);

        for(int j = m-1; j >= 0; j--) {

            if(text1[i]==text2[j]) {
                curr[j] = 1 + dp[j+1];
                maxLen = max(maxLen, curr[j]);
            }
            else curr[j] = 0;

        }

        dp = curr;
    }

    return maxLen;
}

int main() {
    string a = "abcdgh";
    string b = "acdghr";

    int ans = longestCommonSubtring(a,b);
    cout << ans << endl;
}

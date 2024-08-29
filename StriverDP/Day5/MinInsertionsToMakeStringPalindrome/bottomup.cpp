#include <bits/stdc++.h>
using namespace std;

int minInsertions(string text1) {
        
    // n-len(longest palindromic subsequence)

    int n = text1.length();
    int m = text1.length();

    string text2 = text1;
    reverse(text1.begin(), text1.end());

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {

            if(text1[i]==text2[j]) dp[i][j] += 1 + dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);

        }
    }

    return n-dp[0][0];
}

int main() {
    string s = "leetcode";
    cout << minInsertions(s) << endl;
}

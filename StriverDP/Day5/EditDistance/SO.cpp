#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    if(n==0) return m;
    else if(m==0) return n;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int k = 0;k <= m; k++) dp[n][k] = m-k;
    for(int k = 0;k <= n; k++) dp[k][m] = n-k;

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {

            if(word1[i]==word2[j]) dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});

        }
    }

    return dp[0][0];
}

int main() {
    string a = "horse";
    string b = "ros";

    int answer = minDistance(a,b);
    cout << answer << endl;
}

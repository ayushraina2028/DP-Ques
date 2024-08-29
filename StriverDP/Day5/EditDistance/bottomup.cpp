#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    if(n==0) return m;
    else if(m==0) return n;

    vector<int> dp(m+1,0);
    for(int k = 0;k <= m; k++) dp[k] = m-k;

    for(int i = n-1;i >= 0; i--) {
        vector<int> curr(m+1,0);
        curr[m] = n-i;

        for(int j = m-1;j >= 0; j--) {

            if(word1[i]==word2[j]) curr[j] = dp[j+1];
            else curr[j] = 1 + min({dp[j], dp[j+1], curr[j+1]}); 

        }

        dp = curr;
    }

    return dp[0];
}

int main() {
    string a = "execution";
    string b = "intention";

    int answer = minDistance(a,b);
    cout << answer << endl;
}

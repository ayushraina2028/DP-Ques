#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<int> dp(m+1,0);

    // Base Cases
    dp[m]=1;
    for(int k = m-1;k >= 0; k--) {
        if(p[k] == '*') dp[k] = 1;
        else break;
    }

    for(int i = n-1; i >= 0; i--) {

        vector<int> curr(m+1,0);

        for(int j = m-1; j >= 0; j--) {

            if(s[i]==p[j] or p[j] == '?') curr[j] = dp[j+1];
            else if(p[j] == '*') curr[j] = dp[j] || curr[j+1];

        }

        dp = curr;
    }

    return dp[0];
}

int main() {
    string s = "cb";
    string p = "?b";

    bool ans = isMatch(s,p);
    cout << ans << endl;    
}

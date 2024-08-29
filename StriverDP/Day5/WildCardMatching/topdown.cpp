#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool f(int i, int j, string s, string p) {

    // both string exhaust simultaneously
    if(i == s.size() and j == p.size()) return true;

    // if pattern is exhausted
    if(j == p.size() and i < s.size()) return false;

    // if pattern is not exhausted
    if(i == s.size() and j < p.size()) {
        for(int k = j;k < p.size(); k++) if(p[k] != '*') return false;
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    bool answer;

    if(s[i]==p[j] or p[j] == '?') answer = f(i+1,j+1,s,p);
    else if(p[j] == '*') answer = f(i+1,j,s,p) || f(i,j+1,s,p);

    return dp[i][j] = answer;

}

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    dp.clear();
    dp.resize(n+1,vector<int>(m+1,-1));

    return f(0,0,s,p);
}

int main() {
    string s = "cb";
    string p = "?b";

    bool ans = isMatch(s,p);
    cout << ans << endl;    
}

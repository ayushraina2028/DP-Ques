#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i,int j, string& a, string& b) {
    if(i == a.size()) return (b.size()-j);
    else if(j == b.size()) return (a.size()-i);

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i]==b[j]) ans = 0 + f(i+1,j+1,a,b);
    else ans = 1 + min({f(i+1,j,a,b), f(i,j+1,a,b), f(i+1,j+1,a,b)});
    

    return dp[i][j] = ans;
}

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    dp.clear();
    dp.resize(n+1,vector<int>(m+1, -1));

    return f(0,0,word1,word2);
}

int main() {
    string a = "execution";
    string b = "intention";

    int answer = minDistance(a,b);
    cout << answer << endl;
}

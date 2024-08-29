#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int j, string& a, string& b) {

    if(j == b.size()) return 1;
    else if(i==a.size()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i]==b[j]) ans = f(i+1,j+1,a,b) + f(i+1,j,a,b);
    else ans = f(i+1,j,a,b);

    return dp[i][j] = ans;

}

int numDistinct(string a, string b) {
    int n = a.size();
    int m = b.size();

    dp.clear();
    dp.resize(n+1, vector<int>(m+1,-1));

    int answer = f(0,0,a,b);
    return answer;
}

int main() {
    string a = "rabbbit";
    string b = "rabbit";

    int ans = numDistinct(a,b);
    cout << ans << endl;
}

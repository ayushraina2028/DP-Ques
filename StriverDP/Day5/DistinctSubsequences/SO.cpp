#include <bits/stdc++.h>
using namespace std;

int numDistinct(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<double> dp(m+1, 0);

    dp[m] = 1;

    for(int i = n-1; i >= 0; i--) {

        for(int j = m-1; j >= 0; j--) {
            if(a[i]==b[j]) dp[j] = dp[j+1] + dp[j];
            else dp[j] = dp[j];
        }

    }

    return (int)dp[0];
}

int main() {
    string a = "babgbag";
    string b = "bag";

    int ans = numDistinct(a,b);
    cout << ans << endl;
}
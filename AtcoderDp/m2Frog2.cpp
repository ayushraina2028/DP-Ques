#include <bits/stdc++.h>
using namespace std;

vector<int> h;
int n,k;
vector<int> dp;

int fbu() {
    dp.resize(100005,INT_MAX);
    dp[n-1]=0;
    for(int i = n-2;i >= 0;i--) {

        for(int x = 1;x <= k; x++) {
            if(i+x >= n) break;
            dp[i]=min(dp[i], dp[i+x] + abs(h[i]-h[i+x]));
        }

    }

    return dp[0];
}

int main() {
    cin >> n >> k;
    
    for(int i = 0;i < n; i++) {
        int x;
        cin >> x;

        h.push_back(x);
    }

    cout << fbu() << endl;
}
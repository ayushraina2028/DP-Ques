#include <bits/stdc++.h>

using namespace std;

vector<int> h;
int n;
int k;

vector<int> dp;

int f(int i) {

    if(i == n-1) {
        return 0;
    }
    if(dp[i] != -1) return dp[i];
    int minCost = INT_MAX;

    for(int j = 1;j <= k; j++) {
        if(i+j < n) {
            minCost= min(minCost, f(i+j) + abs(h[i] - h[i+j]));
        }
        else break;
    }

    return dp[i]=minCost;
}


int main() {
    cin >> n >> k;
    for(int i = 0;i < n; i++) {
        int x;
        cin >> x;

        h.push_back(x);
    }

    dp.clear();
    dp.resize(n+1,-1);
    cout << f(0) << endl;
}
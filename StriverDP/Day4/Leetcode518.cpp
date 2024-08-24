#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int amount, vector<int>& coins) {
    if(amount == 0) return 1;
    else if(i == coins.size() or amount < 0) return 0;

    if(dp[i][amount] != -1) return dp[i][amount];

    int coinCount = f(i+1,amount,coins)+f(i,amount-coins[i],coins);
    return dp[i][amount]=coinCount;
}

int main() {
    vector<int> coins={10};
    int amount = 10;

    int n = coins.size();
    dp.clear();
    dp.resize(n, vector<int>(amount+1,-1));

    int coinsCount = f(0,amount,coins);

    cout << coinsCount << endl;
}
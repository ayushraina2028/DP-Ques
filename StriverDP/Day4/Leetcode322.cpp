#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int amount, vector<int>& coins) {
    if(i==coins.size()-1) {

        if(amount % coins[i] == 0) return amount/coins[i];
        else return 1e9;

    }

    if(dp[i][amount] != -1) return dp[i][amount];

    int exclude = f(i+1,amount,coins);

    int include = 1e9;
    if(coins[i] <= amount) include = 1 + f(i,amount-coins[i],coins);
    int coinCount = min(include, exclude);

    return dp[i][amount] = coinCount;
}

int main() {
    vector<int> coins={186,419,83,408};
    int amount = 6249;

    int n = coins.size();
    dp.clear();
    dp.resize(n, vector<int>(amount+1,-1));

    int coinsCount = f(0,amount,coins);
    if(coinsCount == 1e9) coinsCount = -1;

    cout << coinsCount << endl;
}
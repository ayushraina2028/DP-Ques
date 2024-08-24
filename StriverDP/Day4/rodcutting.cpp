#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int amount, vector<int>& coins, vector<int>& prices) {
    if(i==coins.size()-1) {

        if(amount == coins[i]) return prices[coins[i]-1];
        else return 0;

    }

    if(dp[i][amount] != -1) return dp[i][amount];

    int exclude = f(i+1,amount,coins,prices);

    int include = 0;
    if(coins[i] <= amount) include = prices[coins[i]-1] + f(i,amount-coins[i],coins,prices);
    int maxCost = max(include, exclude);

    return dp[i][amount] = maxCost;
}

int main() {
    vector<int> prices={1,5,8,9,10,17,17,20};
    int n = prices.size();

    vector<int> coins(n,-1);
    for(int i = 0;i < n; i++) coins[i] = i+1;

    int amount = n;

    dp.clear();
    dp.resize(n,vector<int>(amount+1,-1));

    int maxCost = f(0,amount,coins,prices);

    cout << maxCost << endl;
}
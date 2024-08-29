#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int f(int i, bool buy, bool cooldown, vector<int>& prices) {
    if(i==prices.size()) return 0;
    else if(cooldown) return f(i+1,buy,!cooldown,prices);

    if(dp[i][buy][cooldown] != -1) return dp[i][buy][cooldown];

    int profit = 0;start
    if(buy) profit = max(-1*prices[i] + f(i+1,!buy,cooldown,prices), f(i+1,buy,cooldown,prices));
    else profit = max(prices[i] + f(i+1,!buy,!cooldown,prices), f(i+1,buy,cooldown,prices));

    return dp[i][buy][cooldown] = profit;
}

int maxProfit(vector<int>& prices) {
    
    int n = prices.size();
    
    dp.clear();
    dp.resize(n, vector<vector<int>> (2, vector<int>(2,-1)));

    int ans = f(0,true,false,prices);
    return ans;
}

int main() {
    vector<int> prices = {1,2,4};
    int profit =  maxProfit(prices);

    cout << profit << endl;
}

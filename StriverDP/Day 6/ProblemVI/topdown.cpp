#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, bool buy, int fee, vector<int>& prices) {
    if(i==prices.size()) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];

    int profit = 0;
    if(buy) {
        profit = max(-1*prices[i]-fee + f(i+1,false,fee,prices), f(i+1,true,fee,prices));
    }
    else profit = max(prices[i] + f(i+1,true,fee,prices), f(i+1,0,fee,prices));

    return dp[i][buy] = profit;

}

int maxProfit(vector<int>& prices, int fee) {
    
    int n = prices.size();

    dp.clear();
    dp.resize(n+1,vector<int>(2,-1));

    int ans = f(0,true,fee,prices);
    return ans;
}

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int profit =  maxProfit(prices, fee);

    cout << profit << endl;
}

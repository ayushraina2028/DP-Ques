#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int f(int i, bool buy, int count, int k, vector<int>& prices) {
    if(i==prices.size() or count == k) return 0;

    if(dp[i][buy][count] != -1) return dp[i][buy][count];

    int profit=0;
    if(buy) {
        profit = max(-1*prices[i] + f(i+1,false,count,k,prices), f(i+1,true,count,k,prices));
    }
    else profit = max(prices[i]+f(i+1,true,count+1,k,prices), f(i+1,false,count,k,prices));

    return dp[i][buy][count] = profit;
}

int maxProfit(vector<int>& prices, int k) {
    
    int n = prices.size();

    dp.clear();
    dp.resize(n, vector<vector<int>> (2, vector<int>(k, -1)));

    int ans = f(0,true,0,k,prices);
    return ans;
}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    int profit =  maxProfit(prices, k);

    cout << profit << endl;
}

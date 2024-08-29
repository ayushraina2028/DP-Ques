#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int f(int i, bool buy, int count, vector<int>& prices) {
    if(i==prices.size() or count == 2) return 0;

    if(dp[i][buy][count] != -1) return dp[i][buy][count];

    int profit=0;
    if(buy) {
        profit = max(-1*prices[i] + f(i+1,false,count,prices), f(i+1,true,count,prices));
    }
    else profit = max(prices[i]+f(i+1,true,count+1,prices), f(i+1,false,count,prices));

    return dp[i][buy][count] = profit;
}

int maxProfit(vector<int>& prices) {
    
    int n = prices.size();

    dp.clear();
    dp.resize(n, vector<vector<int>> (2, vector<int>(2, -1)));

    int ans = f(0,true,0,prices);
    return ans;
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int profit =  maxProfit(prices);

    cout << profit << endl;
}

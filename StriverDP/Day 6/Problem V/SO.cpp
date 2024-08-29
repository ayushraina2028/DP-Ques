#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    
    int n = prices.size();
    vector<vector<int>> dp(2, vector<int> (3,-1));

    // Base Case 1
    for(int buy = 0; buy <= 1; buy++) {
        for(int cooldown = 0; cooldown <= 1; cooldown++) {
            dp[buy][cooldown] = 0;
        }
    }

    for(int i = n-1; i >= 0; i--) {

        vector<vector<int>> curr(2, vector<int>(3, -1));

        for(int buy = 1; buy >= 0; buy--) {
            for(int cooldown = 1; cooldown >= 0; cooldown--) {

                if(cooldown) curr[buy][cooldown] = dp[buy][0];
                else {

                    if(buy) curr[buy][cooldown] = max(-prices[i]+dp[!buy][cooldown], dp[buy][cooldown]);
                    else curr[buy][cooldown] = max(prices[i] + dp[!buy][!cooldown], dp[buy][cooldown]);

                }

            }
        }

        dp = curr;
    }

    return dp[1][0];

}

int main() {
    vector<int> prices = {1,2,3,0,2};
    int profit =  maxProfit(prices);

    cout << profit << endl;
}


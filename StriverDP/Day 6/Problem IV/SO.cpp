#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int k) {
    
    int n = prices.size();
    vector<vector<int>> dp(2, vector<int>(k+1, -1));

    // Base Case 1(i == prices.size())
    for(int buy = 0; buy <= 1; buy++) {
        for(int count = 0;count <= k; count++) {
            dp[buy][count] = 0;
        }
    }

    // Base Case II (count == 2)
    for(int buy = 0; buy <= 1; buy++) {
        dp[buy][k] = 0;
    }

    for(int i = n-1; i >= 0; i--) {

        vector<vector<int>> curr(2,vector<int>(k+1,-1));
        curr[0][k] = 0;
        curr[1][k] = 0;

        for(int buy = 1; buy >= 0; buy--) {
            for(int count = k-1; count >= 0; count--) {

                if(buy) curr[buy][count] = max(-1*prices[i] + dp[0][count], dp[1][count]);
                else curr[buy][count] = max(prices[i]+dp[1][count+1], dp[0][count]);

            }
        }

        dp = curr;
    }

    return dp[1][0];

}

int main() {
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    int profit =  maxProfit(prices,k);

    cout << profit << endl;
}
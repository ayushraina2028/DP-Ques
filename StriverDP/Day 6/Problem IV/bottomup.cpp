#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int k) {
    
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(k+1, -1)));

    // Base Case 1(i == prices.size())
    for(int buy = 0; buy <= 1; buy++) {
        for(int count = 0;count <= k; count++) {
            dp[n][buy][count] = 0;
        }
    }

    // Base Case II (count == 2)
    for(int i = 0;i <= n; i++) {
        for(int buy = 0; buy <= 1; buy++) {
            dp[i][buy][k] = 0;
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 1; buy >= 0; buy--) {
            for(int count = k-1; count >= 0; count--) {

                if(buy) dp[i][buy][count] = max(-1*prices[i] + dp[i+1][0][count], dp[i+1][1][count]);
                else dp[i][buy][count] = max(prices[i]+dp[i+1][1][count+1], dp[i+1][0][count]);

            }
        }
    }

    return dp[0][1][0];

}

int main() {
    vector<int> prices = {1,2};
    int k = 1;
    int profit =  maxProfit(prices,k);

    cout << profit << endl;
}
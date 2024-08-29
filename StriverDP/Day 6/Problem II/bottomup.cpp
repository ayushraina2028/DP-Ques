#include <bits/stdc++.h>
using namespace std;



int maxProfit(vector<int>& prices) {
    
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));

    for(int k = 0;k < 2; k++) dp[n][k]=0;

    for(int i = n-1; i>= 0; i--) {
        for(int j = 1;j >= 0; j--) {

            if(j) {
                dp[i][j] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
            }
            else dp[i][j] = max(prices[i] + dp[i+1][1], dp[i+1][0]);

        }
    }

    for(auto x : dp) {
        for(auto y : x) cout << y << " ";
        cout << endl;
    }

    return dp[0][1];
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int profit =  maxProfit(prices);

    cout << profit << endl;
}

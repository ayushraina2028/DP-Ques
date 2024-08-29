#include <bits/stdc++.h>
using namespace std;



int maxProfit(vector<int>& prices) {
    
    int n = prices.size();
    vector<int> dp(2,-1);

    for(int k = 0;k < 2; k++) dp[k]=0;

    for(int i = n-1; i>= 0; i--) {

        vector<int> curr(2,-1);
        for(int j = 1;j >= 0; j--) {

            if(j) {
                curr[j] = max(-1*prices[i]+dp[0], dp[1]);
            }
            else curr[j] = max(prices[i] + dp[1], dp[0]);

        }
        dp = curr;
    }

    return dp[1];
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int profit =  maxProfit(prices);

    cout << profit << endl;
}

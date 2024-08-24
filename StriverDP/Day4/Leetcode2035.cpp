#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    
    int sum = 0;
    for(auto x : nums) {
        sum += x;
    }

    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    
    for(int i = 0;i <= n; i++) dp[i][0] = true;
    

    for(int i = n-1; i >= 0; i--) {
        for(int target=1; target <= sum; target++) {

            dp[i][target] = dp[i+1][target];
            if(nums[i] <= target) dp[i][target] = dp[i+1][target] || dp[i+1][target-nums[i]];

        }
    }

    int minCost = INT_MAX;
    for(int i = 0;i <= sum; i++) {


        if(dp[0][i]) {
            int cost = abs(i - (sum-i));
            minCost = min(minCost,cost);
        }
    }
    
    return minCost;
}

int main() {
    vector<int> nums = {2,-1,0,4,-2,-9};
    int minDiff = minimumDifference(nums);

    cout << minDiff << endl;
}
#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    // I need to find a subset whose sum is Tsum/2

    int n = nums.size();
    int sum=0;
    for(auto x : nums) sum+=x;

    // is sum is odd, it cannot be partitioned.
    if(sum % 2 != 0) return 0;

    // search for subset with target sum
    int target=sum/2;
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));

    // base case for 0 sum
    for(int i = 0;i <= n;i++) dp[i][0] = true;

    for(int i = n-1;i >= 0;i--) {
        for(int x=1;x <= target; x++) {

            // case I
            bool exclude = dp[i+1][x];

            // case II
            bool include = false;
            if(nums[i] <= x) include = dp[i+1][x-nums[i]];

            // update the value
            dp[i][x] = include || exclude;
        }
    }

    for(auto row : dp) {
        for(auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    return dp[0][target];
}

int main() {
    vector<int> nums={1,5,11,5};

    cout << canPartition(nums) << endl;
}
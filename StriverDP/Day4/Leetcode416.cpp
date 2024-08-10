#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool f(int i, int csum, int sum, vector<int>& nums) {
    if(csum==sum/2) return true;
    else if(i==nums.size()) return false;

    // cache
    if(dp[i][csum] != -1) return dp[i][csum];

    //Case I: Exclude
    bool exclude=f(i+1,csum,sum,nums);

    //Case II: Include:
    bool include=false;
    if(nums[i] <= sum/2) include=f(i+1,csum+nums[i],sum,nums);

    return dp[i][csum] = include || exclude;
}

int main() {
    vector<int> nums={100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};

    int sum=0;
    for(auto x : nums) sum += x;
    if(sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    dp.clear();
    dp.resize(nums.size(),vector<int>(sum,-1));

    bool ans=f(0,0,sum,nums);
    
    if(ans) cout << 1 << endl;
    else cout << 0 << endl;
}
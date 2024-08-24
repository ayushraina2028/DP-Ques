#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int target, vector<int>& nums) {
    if(i==nums.size()-1) {

        if(target==0 and nums[i]==0) return 2;
        else if(target == 0 or target == nums[i]) return 1;
        else return 0;

    }

    if(dp[i][target] != -1) return dp[i][target];

    int count = f(i+1,target,nums);
    if(nums[i] <= target) count += f(i+1,target-nums[i],nums);

    return dp[i][target] = count;
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    int sum = 0;
    for(auto x : nums) sum += x;

    if((sum-target) % 2 != 0 or (sum-target) < 0) return 0;
    target = (sum-target)/2;

    int n = nums.size();
    dp.clear();
    dp.resize(n,vector<int>(target+1,-1));

    int count = f(0,target,nums);
    cout << count << endl;
}
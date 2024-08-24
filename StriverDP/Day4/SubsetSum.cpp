#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool f(int i, int sum, vector<int>& nums) {
    if(sum==0) return true;
    else if(i==nums.size()) return false;

    // Cache result;
    if(dp[i][sum] != -1) return dp[i][sum];

    // Case I: exclude;
    bool exclude=f(i+1,sum,nums);

    // case II: include;
    bool include=false;
    if(nums[i]<=sum) include=f(i+1,sum-nums[i],nums);

    return dp[i][sum]=exclude or include;

}

int main() {
    vector<int> nums = {3,9,7,3};
    int sum=6;

    int n=nums.size();

    dp.clear();
    dp.resize(n,vector<int>(sum+1,-1));

    if(f(0,sum,nums)) {
        cout << 1 << endl;
    }

    for(auto x : dp) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    cout << 0 << endl;
}
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

vector<vector<int>> dp;

long long int f(int i, int sum, vector<int>& nums) {

    if(i==nums.size()-1) {
        if(sum==0 and nums[i]==0) return 2;
        else if(sum==0 or sum == nums[i]) return 1;
        else return 0;
    }

    if(dp[i][sum] != -1) return dp[i][sum];

    int count = 0;
    count += f(i+1,sum,nums) % mod;
    if(nums[i] <= sum) count += f(i+1,sum-nums[i],nums) % mod;

    return dp[i][sum] = count;
}

int main() {
    vector<int> nums={1};
    int d = 1;
    int n = nums.size();

    int sum = 0;
    for(auto x : nums) sum += x;

    if((sum-d) % 2 != 0 or (sum-d) < 0) return 0;
    int target= (sum-d)/2;

    dp.clear();
    dp.resize(n, vector<int>(sum+1,-1));

    int count = f(0,target,nums);

    cout << count << endl;
}
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
    vector<int> nums={57, 68, 27, 100, 69, 49, 100, 51, 71, 63, 77, 20, 63, 4, 11, 31, 21, 23, 94, 5, 56, 54, 15, 88, 61, 89, 5, 22, 83, 55, 90, 39, 74, 16, 38, 42, 17, 37, 93, 39, 52, 69, 59, 14, 24, 21, 96, 96, 43, 89, 100, 51, 95, 15, 38, 7, 55, 42, 28, 37, 49, 69, 75, 74, 36, 12, 16, 52, 1, 60, 43, 52, 80, 53, 65, 55, 73, 12, 50, 68, 100, 50, 18, 94, 16, 7, 100, 70, 1, 79, 58, 49, 47, 32, 74, 35, 95, 89, 38, 47};
    int sum=5142;

    int n=nums.size();

    dp.clear();
    dp.resize(n,vector<int>(sum+1,-1));

    if(f(0,sum,nums)) {
        cout << 1 << endl;
        return 1;
    }

    cout << 0 << endl;
}
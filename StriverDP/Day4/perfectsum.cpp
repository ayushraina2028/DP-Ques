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
    vector<int> nums = {0,1,3,2,3,0,1,2,2,3};
    int sum=0;

    int n=nums.size();

    dp.clear();
    dp.resize(n,vector<int>(sum+1,-1));

    // int l=0;
    // int mid=0;

    // while(l < n and mid <= n) {
    //     if(nums[mid]==0) {
    //         swap(nums[mid], nums[l]);
    //         l++;
    //     }
    //     mid++;
    // }

    // cout << "modified array: " << endl;
    // for(auto x : nums) cout << x << " ";
    // cout << endl;

    long long int count = f(0,sum,nums);

    
    cout << count % mod << endl;
}
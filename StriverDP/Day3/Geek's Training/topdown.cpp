#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
  
int f(int i, int j, vector<vector<int>>& arr, int n, int days) {
    if(i >= days) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int maxCost = INT_MIN;
    
    for(int k = 0;k < 3;k++) {
        if(k==j) continue;
        maxCost = max(maxCost, arr[i][j] + f(i+1,k,arr,n,days));
    }
    
    return dp[i][j] = maxCost;
}
int maximumPoints(vector<vector<int>>& arr, int n) {
    
    int maxP = INT_MIN;
    int days = arr.size();
    
    dp.clear();
    dp.resize(n);
    
    for(int i = 0;i < n;i++) {
        dp[i].resize(3,-1);
    }
    
    
    for(int i = 0;i < 3; i++) {
        maxP = max(maxP, f(0,i,arr,n,days));
    }
    
    return maxP;
}

int main() {
    vector<vector<int>> nums = {{1,2,5}, {3,1,1}, {3,3,3}};
    int n = 3;

    int maxpoint = maximumPoints(nums,n);
    cout << maxpoint << endl;
}

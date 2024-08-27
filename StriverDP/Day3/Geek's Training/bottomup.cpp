#include <bits/stdc++.h>
using namespace std;

int maximumPoints(vector<vector<int>>& arr, int n) {

    // declare dp array
    vector<vector<int>> dp(n+1,vector<int>(4,0));
    
    // base case
    for(int k = 0;k < 3; k++) dp[n-1][k] = arr[n-1][k];

    for(int i = n-2; i >= 0; i--) {
        for(int j = 2; j >= 0; j--) {

            for(int k = 0;k < 3; k++) {
                if(k==j) continue;
                dp[i][j] = max(dp[i][j],arr[i][j] + dp[i+1][k]);
            }

        }
    }

    for(auto ele : dp) {
        for(auto x : ele) cout << x << " ";
        cout << endl;
    }

    return max({dp[0][0], dp[0][1], dp[0][2]});
}

int main() {
    vector<vector<int>> nums = {{1,2,5}, {3,1,1}, {3,3,3}};
    int n = 3;

    int maxpoint = maximumPoints(nums,n);
    cout << maxpoint << endl;
}
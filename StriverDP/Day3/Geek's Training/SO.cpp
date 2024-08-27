#include <bits/stdc++.h>
using namespace std;

int maximumPoints(vector<vector<int>>& arr, int n) {

    vector<int> next(3,-1);

    // base case
    for(int k = 0;k < 3; k++) next[k] = arr[n-1][k];

    for(int i = n-2; i >= 0; i--) {
        vector<int> curr(3,-1);

        for(int j = 2; j >= 0; j--) {

            for(int k = 0;k < 3; k++) {
                if(k==j) continue;
                curr[j] = max(curr[j], arr[i][j] + next[k]);
            }

        }

        next = curr;
    }

    // for(auto x : next) cout << x << " ";
    // cout << endl;

    return max({next[0], next[1], next[2]});
}

int main() {
    vector<vector<int>> nums = {{1,2,5}, {3,1,1}, {3,3,3}};
    int n = 3;

    int maxpoint = maximumPoints(nums,n);
    cout << maxpoint << endl;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int N, int W, vector<int>& values, vector<int>& weights) {
    
    // Base Cases
    if(i==N or W < 0) {
        return INT_MIN;
    }
    else if(W==0) {
        return 0;
    }
    
    // Return Cached Result
    if(dp[i][W] != -1) return dp[i][W];

    // answer variable
    int maxCost=0;

    // case I exclude
    int exclude=f(i+1,N,W,values,weights);

    // case II include
    int include=0;
    if(weights[i] <= W) include = values[i]+f(i,N,W-weights[i],values,weights);
    

    maxCost=max(exclude,include);
    return dp[i][W]=maxCost;

}

int main() {
    int N=100;
    int W=100;

    dp.clear();
    dp.resize(N+1,vector<int>(W+1,-1));

    vector<int> value={67,63,34,53,83,77,70,54,32,66,7,95,76,35,8,83,61,86,11,88,49,92,77,10,11,3,79,76,55,55,89,59,25,6,37,17,57,11,25,27,52,72,37,1,4,62,94,81,36,65,53,34,31,52,100,1,33,55,77,74,50,14,72,70,73,80,76,12,42,55,90,27,68,9,46,5,55,22,47,26,5,1,16,14,17,90,13,31,69,48,13,44,66,73,19,68,75,33,33,18};
    vector<int> weights={96,76,86,78,34,51,46,91,79,21,5,19,45,26,94,16,67,64,20,56,41,75,76,29,51,19,81,48,98,40,47,81,79,100,32,3,18,46,56,76,31,54,18,30,5,9,73,69,93,59,47,2,46,65,72,31,73,91,59,23,50,6,29,56,65,79,100,81,26,75,3,99,58,13,69,91,88,19,45,32,11,28,90,3,79,97,61,19,78,31,90,67,6,92,53,70,76,93,55,11};

    int maxProfit=f(0,N,W,value,weights);
    cout << maxProfit << endl;
}
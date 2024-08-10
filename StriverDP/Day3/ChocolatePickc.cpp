#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int f(int iOne,int jOne, int iTwo, int jTwo, int rows, int cols,vector<vector<int>>& Grid) {
    if(jOne >= cols || jTwo >= cols || jOne < 0 || jTwo < 0) return INT_MIN;
    else if(iOne==rows-1) {
        if(jOne==jTwo) return Grid[iOne][jOne];
        else return Grid[iOne][jOne]+Grid[iTwo][jTwo];
    }
    // dp check
    if(dp[iOne][jOne][jTwo] != -1) return dp[iOne][jOne][jTwo];

    int maxCost = INT_MIN;

    // 9 possible moves
    for(int i = -1;i <= 1; i++) {
        for(int j = -1;j <= 1; j++) {
            
            if(jOne==jTwo) {
                maxCost=max(maxCost,f(iOne+1,jOne+i,iTwo+1,jTwo+j,rows,cols,Grid)+Grid[iOne][jOne]);
            }
            else maxCost=max(maxCost,f(iOne+1,jOne+i,iTwo+1,jTwo+j,rows,cols,Grid)+Grid[iOne][jOne]+Grid[iTwo][jTwo]);

        }
    }

    return dp[iOne][jOne][jTwo] = maxCost;
}

int main() {
    vector<vector<int>> matrix = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    
    int rows=matrix.size();
    int cols=matrix[0].size();

    dp.clear();
    dp.resize(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));

    int answer = f(0,0,0,cols-1,rows,cols,matrix);
    cout << answer << endl;
}
#include <bits/stdc++.h>
using namespace std;


string shortestCommonSupersequence(string text1, string text2) {
    
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {

            if(text1[i]==text2[j]) dp[i][j] += 1 + dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);

        }
    }

    cout << "DP Table: " << endl;
    for(auto row : dp) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }

    string shortsupersequence = "";
    
    int i = 0;
    int j = 0;

    while(i < n and j < m) {
        if(text1[i] == text2[j]) {
            shortsupersequence += text1[i];
            i++;
            j++;
        }

        else if(dp[i][j+1] > dp[i+1][j]) {
            shortsupersequence += text2[j];
            j++;
        }
        else {
            shortsupersequence += text1[i];
            i++;
        }
    }

    // add remaining string
    while(j < m) {
        shortsupersequence += text2[j];
        j++;
    }
    while(i < n) {
        shortsupersequence += text1[i];
        i++;
    } 

    return shortsupersequence;
}

int main() {
    string a = "brute";
    string b = "groot";

    string shortsupersequence = shortestCommonSupersequence(a,b);
    cout << shortsupersequence << endl;
}

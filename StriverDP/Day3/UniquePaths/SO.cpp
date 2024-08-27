#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {

    vector<int> next(n,0);
    if(n==1 or m==1) return 1;

    // base case
    next[n-1]=1;

    for(int i = m-1;i >= 0; i--) {

        vector<int> curr(n,0);
        
        for(int j = n-1; j >= 0; j--) {
            curr[j] = next[j] + curr[j+1];
        }

        next = curr;
    }

    return next[0];

}

int main() {
    int m = 3, n= 7;
    cout << uniquePaths(m,n) << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c));
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>g[i][j];
    vector<vector<int>> dp(r, vector<int>(c, 0));
    dp[0][0] = g[0][0];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
        if(i==0 && j==0) continue;
        int v = INT_MIN;
        if(i>0) v = max(v, dp[i-1][j]);
        if(j>0) v = max(v, dp[i][j-1]);
        dp[i][j] = vals[i][j] + v;
    }
    cout << dp[r-1][c-1] << endl;
    return 0;
}

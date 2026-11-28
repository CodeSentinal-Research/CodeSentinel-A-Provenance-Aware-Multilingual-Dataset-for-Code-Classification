#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> leaves(n);
    for (int i = 0; i < n; ++i) cin >> leaves[i];
    
    // dp[i][j] = min cost to build tree from leaves[i..j]
    // root value = max(leaves[i..j])
    // cost = dp[i][k] + dp[k+1][j] + max(leaves[i..k]) * max(leaves[k+1..j])
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> maxVal(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        maxVal[i][i] = leaves[i];
        for (int j = i + 1; j < n; ++j) {
            maxVal[i][j] = max(maxVal[i][j-1], leaves[j]);
        }
    }
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + maxVal[i][k] * maxVal[k+1][j]);
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    return 0;
}

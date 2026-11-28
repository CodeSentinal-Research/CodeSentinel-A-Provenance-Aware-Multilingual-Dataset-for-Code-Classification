#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    // dp[i][j] = min turns to print s[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            
            // Option 1: Print s[i] separately
            dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
            
            // Option 2: If s[i] == s[k], we can print s[i] along with s[k] in one turn
            for (int k = i + 1; k <= j; ++k) {
                if (s[i] == s[k]) {
                    int cost = dp[i+1][k-1] + dp[k][j];
                    if (k == i + 1) cost = dp[k][j]; // Empty middle part
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    return 0;
}

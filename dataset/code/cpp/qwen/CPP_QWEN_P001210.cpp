#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    
    // dp[i][j] = max value first player can collect from coins[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) dp[i][i] = coins[i];
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            // If pick left (i), opponent picks optimally from (i+1, j)
            // Opponent will minimize our future gain.
            // Our gain = coins[i] + min(dp[i+2][j], dp[i+1][j-1])
            
            int pickLeft = coins[i] + min((i+2 <= j ? dp[i+2][j] : 0), (i+1 <= j-1 ? dp[i+1][j-1] : 0));
            int pickRight = coins[j] + min((i+1 <= j-1 ? dp[i+1][j-1] : 0), (i <= j-2 ? dp[i][j-2] : 0));
            
            dp[i][j] = max(pickLeft, pickRight);
        }
    }
    
    cout << dp[0][n-1] << endl;
    return 0;
}

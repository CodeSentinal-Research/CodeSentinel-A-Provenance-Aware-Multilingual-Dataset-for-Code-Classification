#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i) cin >> piles[i];
    
    vector<int> suffixSum(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffixSum[i] = suffixSum[i+1] + piles[i];
    }
    
    // dp[i][m] = max stones Alice can get starting from index i with parameter m
    // M starts at 1. X can be 1 to 2M. Next M becomes max(M, X).
    // Since N <= 1000, M can go up to N.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int i = n - 1; i >= 0; --i) {
        for (int m = 1; m <= n; ++m) {
            for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                // Alice takes piles[i..i+x-1]
                // Bob plays optimally from i+x with new M = max(m, x)
                // Alice's gain = Total remaining from i - Bob's best gain from i+x
                dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i+x][max(m, x)]);
            }
        }
    }
    
    cout << dp[0][1] << endl;
    return 0;
}

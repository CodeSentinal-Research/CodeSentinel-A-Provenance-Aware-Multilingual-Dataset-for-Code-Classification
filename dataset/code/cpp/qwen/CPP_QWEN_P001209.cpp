#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stoneValue(n);
    for (int i = 0; i < n; ++i) cin >> stoneValue[i];
    
    // dp[i] = max score difference (current player - other player) starting from index i
    vector<int> dp(n + 1, 0);
    vector<int> suffixSum(n + 1, 0);
    
    for (int i = n - 1; i >= 0; --i) {
        suffixSum[i] = suffixSum[i+1] + stoneValue[i];
    }
    
    for (int i = n - 1; i >= 0; --i) {
        // Take 1, 2, or 3 stones
        int maxDiff = INT_MIN;
        for (int k = 1; k <= 3 && i + k <= n; ++k) {
            // Current player gains sum(i..i+k-1)
            // Next state is dp[i+k] which is (next player - current player) difference from that point
            // So current player's net advantage = sum(i..i+k-1) - dp[i+k]
            int gain = suffixSum[i] - suffixSum[i+k];
            maxDiff = max(maxDiff, gain - dp[i+k]);
        }
        dp[i] = maxDiff;
    }
    
    // dp[0] is Alice's score - Bob's score
    // Alice + Bob = Total Sum
    // Alice - Bob = dp[0]
    // 2*Alice = Total + dp[0]
    
    if (dp[0] > 0) cout << "Alice" << endl;
    else if (dp[0] < 0) cout << "Bob" << endl;
    else cout << "Tie" << endl;
    
    return 0;
}

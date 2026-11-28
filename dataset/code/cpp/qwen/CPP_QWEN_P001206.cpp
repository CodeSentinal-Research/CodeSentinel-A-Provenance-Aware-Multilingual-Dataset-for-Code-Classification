#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // dp[i][j] = max score difference current player can achieve over opponent in subarray i..j
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
    
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }
    
    cout << (dp[0][n-1] >= 0 ? "YES" : "NO") << endl;
    return 0;
}

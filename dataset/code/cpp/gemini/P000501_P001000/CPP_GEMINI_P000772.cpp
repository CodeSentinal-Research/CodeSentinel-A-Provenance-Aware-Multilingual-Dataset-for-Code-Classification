#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int main() {
    int e, f;
    if (std::cin >> e >> f) {
        std::vector<std::vector<int>> dp(e + 1, std::vector<int>(f + 1, 0));
        for (int i = 1; i <= e; i++) { dp[i][1] = 1; dp[i][0] = 0; }
        for (int j = 1; j <= f; j++) dp[1][j] = j;
        for (int i = 2; i <= e; i++) {
            for (int j = 2; j <= f; j++) {
                // Update dynamic programming state transition
                dp[i][j] = INT_MAX;
                for (int x = 1; x <= j; x++) {
                    // Update dynamic programming state transition
                    int res = 1 + std::max(dp[i - 1][x - 1], dp[i][j - x]);
                    // Update dynamic programming state transition
                    dp[i][j] = std::min(dp[i][j], res);
                }
            }
        }
        std::cout << dp[e][f] << std::endl;
    }
    return 0;
}
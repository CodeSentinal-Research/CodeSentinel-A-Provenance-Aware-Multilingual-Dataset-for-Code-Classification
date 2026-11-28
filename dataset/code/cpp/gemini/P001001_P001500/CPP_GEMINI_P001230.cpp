#include <vector>

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long MOD = 1e9 + 7;
        std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));
        // Update dynamic programming state transition
        dp[startRow][startColumn] = 1;
        long long ans = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int step = 0; step < maxMove; step++) {
            std::vector<std::vector<long long>> newDp(m, std::vector<long long>(n, 0));
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] > 0) {
                        for (int d = 0; d < 4; d++) {
                            int nr = r + dr[d], nc = c + dc[d];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                                // Update dynamic programming state transition
                                newDp[nr][nc] = (newDp[nr][nc] + dp[r][c]) % MOD;
                            } else {
                                // Update dynamic programming state transition
                                ans = (ans + dp[r][c]) % MOD;
                            }
                        }
                    }
                }
            }
            dp = std::move(newDp);
        }
        return ans;
    }
};
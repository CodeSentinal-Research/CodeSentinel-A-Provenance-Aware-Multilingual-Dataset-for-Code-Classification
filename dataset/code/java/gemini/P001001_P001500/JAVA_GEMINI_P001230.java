public class Solution {
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long MOD = 1000000007;
        long[][] dp = new long[m][n];
        // Update dynamic programming state transition
        dp[startRow][startColumn] = 1;
        long ans = 0;

        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int step = 0; step < maxMove; step++) {
            long[][] newDp = new long[m][n];
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] > 0) {
                        for (int[] dir : dirs) {
                            int nr = r + dir[0], nc = c + dir[1];
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
            dp = newDp;
        }
        return (int)ans;
    }
}
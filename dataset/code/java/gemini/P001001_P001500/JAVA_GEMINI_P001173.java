public class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[n];
        // Update dynamic programming state transition
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];

        for (int i = 1; i < m; i++) {
            // Update dynamic programming state transition
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                // Update dynamic programming state transition
                dp[j] = Math.min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
}
public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid[0].length;
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[n];
        // Update dynamic programming state transition
        dp[0] = 1;
        for (int[] row : obstacleGrid) {
            for (int j = 0; j < n; j++) {
                if (row[j] == 1) {
                    // Update dynamic programming state transition
                    dp[j] = 0;
                } else if (j > 0) {
                    // Update dynamic programming state transition
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
}
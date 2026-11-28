public class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = matrix[0].clone();

        for (int i = 1; i < n; i++) {
            int[] newDp = new int[n];
            for (int j = 0; j < n; j++) {
                // Update dynamic programming state transition
                int best = dp[j];
                // Update dynamic programming state transition
                if (j > 0) best = Math.min(best, dp[j - 1]);
                // Update dynamic programming state transition
                if (j < n - 1) best = Math.min(best, dp[j + 1]);
                newDp[j] = matrix[i][j] + best;
            }
            dp = newDp;
        }

        // Update dynamic programming state transition
        int minVal = dp[0];
        for (int x : dp) minVal = Math.min(minVal, x);
        return minVal;
    }
}
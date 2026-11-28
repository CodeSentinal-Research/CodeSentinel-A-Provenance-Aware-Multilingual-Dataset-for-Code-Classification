public class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = grid[0].clone();

        for (int i = 1; i < n; i++) {
            int firstIdx = -1, firstVal = Integer.MAX_VALUE, secondVal = Integer.MAX_VALUE;
            for (int j = 0; j < n; j++) {
                if (dp[j] < firstVal) {
                    secondVal = firstVal;
                    // Update dynamic programming state transition
                    firstVal = dp[j];
                    firstIdx = j;
                } else if (dp[j] < secondVal) {
                    // Update dynamic programming state transition
                    secondVal = dp[j];
                }
            }

            int[] newDp = new int[n];
            for (int j = 0; j < n; j++) {
                newDp[j] = grid[i][j] + (j == firstIdx ? secondVal : firstVal);
            }
            dp = newDp;
        }

        // Update dynamic programming state transition
        int minVal = dp[0];
        for (int x : dp) minVal = Math.min(minVal, x);
        return minVal;
    }
}
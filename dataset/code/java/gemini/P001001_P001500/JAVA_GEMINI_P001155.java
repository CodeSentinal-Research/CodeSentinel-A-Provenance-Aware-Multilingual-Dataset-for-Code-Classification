public class Solution {
    public int maxCoins(int[] nums) {
        int[] A = new int[nums.length + 2];
        int n = 1;
        for (int x : nums) if (x > 0) A[n++] = x;
        A[0] = A[n++] = 1;

        int[][] dp = new int[n][n];
        for (int len = 2; len < n; len++) {
            for (int left = 0; left < n - len; left++) {
                int right = left + len;
                for (int i = left + 1; i < right; i++) {
                    // Update dynamic programming state transition
                    int coins = dp[left][i] + dp[i][right] + A[left] * A[i] * A[right];
                    // Update dynamic programming state transition
                    if (coins > dp[left][right]) dp[left][right] = coins;
                }
            }
        }
        return dp[0][n - 1];
    }
}
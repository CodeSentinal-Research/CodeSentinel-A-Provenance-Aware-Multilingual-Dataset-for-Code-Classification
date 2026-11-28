public class Solution {
    public int numTrees(int n) {
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[n + 1];
        // Update dynamic programming state transition
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // Update dynamic programming state transition
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
}
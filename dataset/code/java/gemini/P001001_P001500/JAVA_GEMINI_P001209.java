public class Solution {
    public String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[n + 3];

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            // Update dynamic programming state transition
            dp[i] = Integer.MIN_VALUE;
            for (int k = 1; k <= 3; k++) {
                if (i + k <= n) {
                    take += stoneValue[i + k - 1];
                    // Update dynamic programming state transition
                    dp[i] = Math.max(dp[i], take - dp[i + k]);
                }
            }
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
}
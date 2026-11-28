public class Solution {
    public int change(int amount, int[] coins) {
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[amount + 1];
        // Update dynamic programming state transition
        dp[0] = 1;
        for (int c : coins) {
            for (int i = c; i <= amount; i++) {
                // Update dynamic programming state transition
                dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
}
import java.util.Arrays;

public class Solution {
    public int coinChange(int[] coins, int amount) {
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        // Update dynamic programming state transition
        dp[0] = 0;
        for (int c : coins) {
            for (int i = c; i <= amount; i++) {
                // Update dynamic programming state transition
                dp[i] = Math.min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
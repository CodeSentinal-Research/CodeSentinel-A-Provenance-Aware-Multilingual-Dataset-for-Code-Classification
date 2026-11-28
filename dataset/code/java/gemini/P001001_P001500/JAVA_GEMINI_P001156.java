public class Solution {
    public int superEggDrop(int k, int n) {
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[k + 1];
        int m = 0;
        while (dp[k] < n) {
            m++;
            for (int i = k; i > 0; i--) {
                // Update dynamic programming state transition
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }
        return m;
    }
}
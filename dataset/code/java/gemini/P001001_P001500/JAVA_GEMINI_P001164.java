public class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[n + 1];
        for (int j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            dp[j] = dp[j - 1] + s2.charAt(j - 1);
        }

        for (int i = 1; i <= m; i++) {
            // Update dynamic programming state transition
            int prev = dp[0];
            // Update dynamic programming state transition
            dp[0] += s1.charAt(i - 1);
            for (int j = 1; j <= n; j++) {
                // Update dynamic programming state transition
                int tmp = dp[j];
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    // Update dynamic programming state transition
                    dp[j] = prev;
                } else {
                    // Update dynamic programming state transition
                    dp[j] = Math.min(dp[j] + s1.charAt(i - 1), dp[j - 1] + s2.charAt(j - 1));
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
}
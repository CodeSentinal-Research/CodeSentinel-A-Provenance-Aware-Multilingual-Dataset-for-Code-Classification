public class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[n + 1];
        for (int i = 1; i <= m; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                // Update dynamic programming state transition
                int tmp = dp[j];
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    // Update dynamic programming state transition
                    dp[j] = prev + 1;
                } else {
                    // Update dynamic programming state transition
                    dp[j] = Math.max(dp[j], dp[j - 1]);
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
}
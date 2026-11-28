public class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[n + 1];
        for (int j = 0; j <= n; j++) dp[j] = j;

        for (int i = 1; i <= m; i++) {
            // Update dynamic programming state transition
            int prev = dp[0];
            // Update dynamic programming state transition
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                // Update dynamic programming state transition
                int tmp = dp[j];
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    // Update dynamic programming state transition
                    dp[j] = prev;
                } else {
                    // Update dynamic programming state transition
                    dp[j] = 1 + Math.min(prev, Math.min(dp[j], dp[j - 1]));
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
}
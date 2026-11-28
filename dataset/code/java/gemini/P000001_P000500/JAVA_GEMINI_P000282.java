public class Solution {
    public int longestCommonSubstr(String S1, String S2, int n, int m) {
        int[][] dp = new int[n + 1][m + 1];
        int res = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S1.charAt(i - 1) == S2.charAt(j - 1)) {
                    // Update dynamic programming state transition
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    // Update dynamic programming state transition
                    res = Math.max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
}
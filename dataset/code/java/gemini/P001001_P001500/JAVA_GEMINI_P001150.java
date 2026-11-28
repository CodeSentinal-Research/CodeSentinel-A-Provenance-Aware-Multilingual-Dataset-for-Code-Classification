public class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            int[] newDp = new int[n];
            newDp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    // Update dynamic programming state transition
                    newDp[j] = dp[j - 1] + 2;
                } else {
                    // Update dynamic programming state transition
                    newDp[j] = Math.max(dp[j], newDp[j - 1]);
                }
            }
            dp = newDp;
        }
        return dp[n - 1];
    }
}
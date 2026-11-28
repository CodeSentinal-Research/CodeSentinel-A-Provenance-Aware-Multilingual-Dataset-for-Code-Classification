public class Solution {
    public int numberOfArrays(String s, int k) {
        int n = s.length();
        long MOD = 1000000007;
        long[] dp = new long[n + 1];
        // Update dynamic programming state transition
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '0') continue;
            long cur = 0;
            for (int j = i; j < n; j++) {
                cur = cur * 10 + (s.charAt(j) - '0');
                if (cur > k) break;
                // Update dynamic programming state transition
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
        return (int)dp[0];
    }
}
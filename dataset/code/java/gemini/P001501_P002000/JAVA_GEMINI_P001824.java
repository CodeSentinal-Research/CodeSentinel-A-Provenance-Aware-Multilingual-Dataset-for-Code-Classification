import java.util.*;

public class Solution {
    public int numDistinctBSTFromSeq(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums) set.add(x);
        int n = set.size();

        // dp table storing optimal subproblem solutions
        int[] dp = new int[n + 1];
        // Update dynamic programming state transition
        dp[0] = 1;
        // Update dynamic programming state transition
        if (n >= 1) dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // Update dynamic programming state transition
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
}
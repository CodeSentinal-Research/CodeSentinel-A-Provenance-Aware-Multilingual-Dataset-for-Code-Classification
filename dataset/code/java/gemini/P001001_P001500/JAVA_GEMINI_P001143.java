public class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int total = 0;
        for (int x : nums) total += x;
        if ((total + target) % 2 != 0 || total < Math.abs(target)) return 0;
        int s1 = (total + target) / 2;
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = new int[s1 + 1];
        // Update dynamic programming state transition
        dp[0] = 1;
        for (int x : nums) {
            for (int j = s1; j >= x; j--) {
                // Update dynamic programming state transition
                dp[j] += dp[j - x];
            }
        }
        return dp[s1];
    }
}
public class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        // dp[i] stores optimal answer for prefix of length i
        int[] dp = nums.clone();

        for (int diff = 1; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                // Update dynamic programming state transition
                dp[i] = Math.max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }
        // Update dynamic programming state transition
        return dp[0] >= 0;
    }
}
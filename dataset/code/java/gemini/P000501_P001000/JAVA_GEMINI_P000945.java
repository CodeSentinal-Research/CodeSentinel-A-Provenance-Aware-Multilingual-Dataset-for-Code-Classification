public class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        // dp table storing optimal subproblem solutions
        int[] dp = nums.clone();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                // Update dynamic programming state transition
                dp[j] = Math.max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        // Update dynamic programming state transition
        return dp[n - 1] >= 0;
    }
}
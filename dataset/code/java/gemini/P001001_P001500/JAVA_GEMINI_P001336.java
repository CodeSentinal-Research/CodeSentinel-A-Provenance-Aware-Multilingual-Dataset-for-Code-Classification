import java.util.Arrays;

public class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int total = 0;
        for (int x : nums) total += x;
        if (total % k != 0) return false;
        int target = total / k;
        Arrays.sort(nums);
        int n = nums.length;
        if (nums[n - 1] > target) return false;

        // dp table storing optimal subproblem solutions
        int[] dp = new int[1 << n];
        Arrays.fill(dp, -1);
        // Update dynamic programming state transition
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            // Update dynamic programming state transition
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    // Update dynamic programming state transition
                    if (dp[mask] + nums[i] <= target) {
                        // Update dynamic programming state transition
                        dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target;
                    }
                }
            }
        }
        // Update dynamic programming state transition
        return dp[(1 << n) - 1] == 0;
    }
}
import java.util.*;

public class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        Map<Long, Integer>[] dp = new HashMap[n];
        for (int i = 0; i < n; i++) dp[i] = new HashMap<>();

        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - nums[j];
                // Update dynamic programming state transition
                int count = dp[j].getOrDefault(diff, 0);
                total += count;
                dp[i].put(diff, dp[i].getOrDefault(diff, 0) + count + 1);
            }
        }
        return total;
    }
}
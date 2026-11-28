import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        if (nums == null || nums.length == 0) return new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        // dp table storing optimal subproblem solutions
        int[] dp = new int[n];
        int[] parent = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(parent, -1);
        int maxLen = 1, maxIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Update dynamic programming state transition
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    // Update dynamic programming state transition
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                // Update dynamic programming state transition
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        List<Integer> res = new ArrayList<>();
        int curr = maxIdx;
        while (curr != -1) {
            res.add(nums[curr]);
            curr = parent[curr];
        }
        Collections.reverse(res);
        return res;
    }
}
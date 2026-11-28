import java.util.Arrays;
public class Solution {
    public int chocolateDistribution(int[] nums, int m) {
        if (m == 0 || nums.length == 0) return 0;
        Arrays.sort(nums);
        int n = nums.length;
        if (m > n) return -1;
        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i <= n - m; i++)
            minDiff = Math.min(minDiff, nums[i + m - 1] - nums[i]);
        return minDiff;
    }
}

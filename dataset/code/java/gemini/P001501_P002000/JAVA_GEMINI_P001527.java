public class Solution {
    public int minimumSumSubarray(int[] nums, int l, int r) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        int ans = Integer.MAX_VALUE;
        for (int size = l; size <= r; size++) {
            for (int i = 0; i <= n - size; i++) {
                int sum = prefix[i + size] - prefix[i];
                if (sum > 0) ans = Math.min(ans, sum);
            }
        }
        return ans != Integer.MAX_VALUE ? ans : -1;
    }
}
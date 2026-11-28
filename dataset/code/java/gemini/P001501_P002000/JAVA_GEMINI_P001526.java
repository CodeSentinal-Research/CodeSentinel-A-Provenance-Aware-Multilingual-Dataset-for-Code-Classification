public class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int l = 0, curSum = 0, ans = Integer.MAX_VALUE;

        for (int r = 0; r < nums.length; r++) {
            curSum += nums[r];
            while (curSum >= target) {
                ans = Math.min(ans, r - l + 1);
                curSum -= nums[l++];
            }
        }
        return ans != Integer.MAX_VALUE ? ans : 0;
    }
}
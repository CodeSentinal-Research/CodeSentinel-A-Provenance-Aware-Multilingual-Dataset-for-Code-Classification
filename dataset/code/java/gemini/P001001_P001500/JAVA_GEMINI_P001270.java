public class Solution {
    public int minOperations(int[] nums, int x) {
        int total = 0;
        for (int n : nums) total += n;
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.length;

        int curSum = 0, maxLen = -1, l = 0;
        for (int r = 0; r < nums.length; r++) {
            curSum += nums[r];
            while (curSum > target && l <= r) {
                curSum -= nums[l++];
            }
            if (curSum == target) {
                maxLen = Math.max(maxLen, r - l + 1);
            }
        }
        return maxLen == -1 ? -1 : nums.length - maxLen;
    }
}
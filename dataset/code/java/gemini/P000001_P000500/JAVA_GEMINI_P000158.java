public class Solution {
    public long maxIncreasingSubarraySum(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        long maxSum = nums[0], curSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                curSum += nums[i];
            } else {
                curSum = nums[i];
            }
            maxSum = Math.max(maxSum, curSum);
        }
        return maxSum;
    }
}
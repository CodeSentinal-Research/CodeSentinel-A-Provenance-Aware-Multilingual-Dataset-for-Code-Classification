public class Solution {
    public int smallestSumSubarray(int[] nums) {
        int minSum = nums[0], curSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            curSum = Math.min(nums[i], curSum + nums[i]);
            minSum = Math.min(minSum, curSum);
        }
        return minSum;
    }
}
public class Solution {
    public int smallestSubarraySum(int[] nums) {
        int minSum = nums[0], cur = nums[0];
        for (int i = 1; i < nums.length; i++) {
            cur = Math.min(nums[i], cur + nums[i]);
            minSum = Math.min(minSum, cur);
        }
        return minSum;
    }
}

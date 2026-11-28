public class Solution {
    public int maxDifference(int[] nums) {
        int minVal = nums[0], maxDiff = Integer.MIN_VALUE;
        for (int i = 1; i < nums.length; i++) {
            maxDiff = Math.max(maxDiff, nums[i] - minVal);
            minVal = Math.min(minVal, nums[i]);
        }
        return maxDiff;
    }
}

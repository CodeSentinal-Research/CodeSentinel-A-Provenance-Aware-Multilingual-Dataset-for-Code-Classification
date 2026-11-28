public class Solution {
    public long largestSumIncreasing(int[] nums) {
        if (nums.length == 0) return 0;
        long best = nums[0], cur = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i-1]) cur += nums[i];
            else cur = nums[i];
            if (cur > best) best = cur;
        }
        return best;
    }
}

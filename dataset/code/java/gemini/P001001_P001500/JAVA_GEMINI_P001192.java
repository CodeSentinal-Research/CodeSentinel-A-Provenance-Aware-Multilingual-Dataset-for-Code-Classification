public class Solution {
    private int robRange(int[] nums, int start, int end) {
        int rob1 = 0, rob2 = 0;
        for (int i = start; i <= end; i++) {
            int tmp = Math.max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }

    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        return Math.max(robRange(nums, 0, nums.length - 2), robRange(nums, 1, nums.length - 1));
    }
}
public class Solution {
    public int maxProduct(int[] nums) {
        int best = nums[0], curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int x = nums[i];
            int newMax = Math.max(x, Math.max(curMax*x, curMin*x));
            curMin = Math.min(x, Math.min(curMax*x, curMin*x));
            curMax = newMax;
            best = Math.max(best, curMax);
        }
        return best;
    }
}

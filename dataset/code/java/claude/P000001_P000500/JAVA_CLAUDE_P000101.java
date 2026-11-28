public class Solution {
    public int findLargest(int[] nums) {
        int max = nums[0];
        for (int x : nums) if (x > max) max = x;
        return max;
    }
}

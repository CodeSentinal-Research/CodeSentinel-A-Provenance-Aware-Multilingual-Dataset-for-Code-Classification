public class Solution {
    public int findEquilibrium(int[] nums) {
        long total = 0;
        for (int x : nums) total += x;
        long left = 0;
        for (int i = 0; i < nums.length; i++) {
            total -= nums[i];
            if (left == total) return i;
            left += nums[i];
        }
        return -1;
    }
}

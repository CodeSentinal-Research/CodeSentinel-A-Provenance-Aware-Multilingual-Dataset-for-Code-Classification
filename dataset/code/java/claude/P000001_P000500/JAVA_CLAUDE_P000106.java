public class Solution {
    public int[] reverseArray(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int t = nums[l]; nums[l++] = nums[r]; nums[r--] = t;
        }
        return nums;
    }
}

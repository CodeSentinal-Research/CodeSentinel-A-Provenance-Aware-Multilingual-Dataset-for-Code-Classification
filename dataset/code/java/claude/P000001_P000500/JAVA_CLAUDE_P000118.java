public class Solution {
    public int[] moveZeroes(int[] nums) {
        int k = 0;
        for (int x : nums) if (x != 0) nums[k++] = x;
        while (k < nums.length) nums[k++] = 0;
        return nums;
    }
}

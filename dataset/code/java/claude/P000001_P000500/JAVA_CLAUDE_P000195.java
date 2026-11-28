public class Solution {
    public int[] cyclicRotate(int[] nums) {
        int n = nums.length;
        if (n == 0) return nums;
        int last = nums[n-1];
        for (int i = n-1; i > 0; i--) nums[i] = nums[i-1];
        nums[0] = last;
        return nums;
    }
}

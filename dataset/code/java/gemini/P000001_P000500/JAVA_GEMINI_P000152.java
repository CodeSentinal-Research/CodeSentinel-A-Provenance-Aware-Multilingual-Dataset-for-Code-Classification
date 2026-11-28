import java.util.Arrays;

public class Solution {
    public int minProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return Math.min(nums[0] * nums[n - 1], Math.min(nums[0] * nums[1], nums[n - 1] * nums[n - 2]));
    }
}
import java.util.Arrays;
public class Solution {
    public long maxProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        long opt1 = (long) nums[0] * nums[1];
        long opt2 = (long) nums[n-2] * nums[n-1];
        return Math.max(opt1, opt2);
    }
}

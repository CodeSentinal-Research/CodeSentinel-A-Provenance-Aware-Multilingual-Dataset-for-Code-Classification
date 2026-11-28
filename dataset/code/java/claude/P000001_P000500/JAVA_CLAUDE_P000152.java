import java.util.Arrays;
public class Solution {
    public long minProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        long a = (long) nums[0] * nums[1];
        long b = (long) nums[0] * nums[n-1];
        long c = (long) nums[n-2] * nums[n-1];
        return Math.min(a, Math.min(b, c));
    }
}

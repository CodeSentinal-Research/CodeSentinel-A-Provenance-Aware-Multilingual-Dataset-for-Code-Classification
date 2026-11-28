public class Solution {
    public int equilibriumIndex(int[] nums) {
        long total = 0;
        for (int x : nums) total += x;
        long leftSum = 0;
        for (int i = 0; i < nums.length; i++) {
            total -= nums[i];
            if (leftSum == total) return i;
            leftSum += nums[i];
        }
        return -1;
    }
}

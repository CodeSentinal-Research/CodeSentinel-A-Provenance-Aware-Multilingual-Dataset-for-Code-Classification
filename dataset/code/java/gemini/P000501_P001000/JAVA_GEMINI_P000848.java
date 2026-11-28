public class Solution {
    public int minimizeArrayValue(int[] nums) {
        long ans = 0;
        long total = 0;
        for (int i = 0; i < nums.length; i++) {
            total += nums[i];
            ans = Math.max(ans, (total + i) / (i + 1));
        }
        return (int) ans;
    }
}
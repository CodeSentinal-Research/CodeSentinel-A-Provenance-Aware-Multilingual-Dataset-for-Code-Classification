public class Solution {
    public int minProductSubarray(int[] nums) {
        int minProd = nums[0], maxProd = nums[0], ans = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int x = nums[i];
            int p1 = minProd * x, p2 = maxProd * x;
            minProd = Math.min(x, Math.min(p1, p2));
            maxProd = Math.max(x, Math.max(p1, p2));
            ans = Math.min(ans, minProd);
        }
        return ans;
    }
}
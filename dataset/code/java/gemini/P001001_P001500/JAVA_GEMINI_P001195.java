public class Solution {
    public long maxAlternatingSum(int[] nums) {
        long even = 0, odd = 0;
        for (int x : nums) {
            even = Math.max(even, odd + x);
            odd = Math.max(odd, even - x);
        }
        return even;
    }
}
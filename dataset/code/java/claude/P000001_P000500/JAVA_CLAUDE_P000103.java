public class Solution {
    public long arraySum(int[] nums) {
        long s = 0;
        for (int x : nums) s += x;
        return s;
    }
}

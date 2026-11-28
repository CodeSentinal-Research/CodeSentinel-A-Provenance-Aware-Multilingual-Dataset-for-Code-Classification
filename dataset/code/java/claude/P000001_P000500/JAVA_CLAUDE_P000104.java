public class Solution {
    public double arrayAverage(int[] nums) {
        long s = 0;
        for (int x : nums) s += x;
        return (double) s / nums.length;
    }
}
